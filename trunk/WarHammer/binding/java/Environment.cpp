/*
 *        M   M  M  MMM                     UUU
 *        M   M M M M M                     U    U   U
 *   WWWW M M M M M MMM                     U   UUU UUU WWWW
 *   WWWW MM MM MMM MM                      U    U   U  WWWW
 *   WW   M   M M M M M       HH HH         UUU           WW
 *   WW                       HH HH                       WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW                       HH HH                       WW
 *   WW                       HH HH                       WW
 *   WWWW                     HH HH                     WWWW
 *   WWWW                     HH HH                     WWWW
 *                            HH HH
 *                            HH HH NNN NNN NNN NNN NNN NNN NNN
 *                            HH HH N N N N N N   N N   N    N
 *                            HH HH NNN NNN N N N N NN  N    N
 *                                  N   NN  N N N N N   N    N
 *                                N N   N N NNN NNN NNN NNN  N
 *
 * Environment.cpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Environment.hpp"
#include "exception/EnvironmentException.hpp"
#include "../../exception/Exception.hpp"

WarHammer::binding::java::Environment::Environment(void)
{
	this->_JNIEnvironment = NULL;
	this->_javaVM = NULL;
}

WarHammer::binding::java::Environment::~Environment(void)
{
	this->_javaVM->DestroyJavaVM();

	delete this->_javaVM;
	delete this->_JNIEnvironment;
	this->_classes.clear();
}

WarHammer::util::SmartPointer<WarHammer::binding::java::Class> WarHammer::binding::java::Environment::getClass(WarHammer::util::String className)
{
	if(!this->_JNIEnvironment)
		ThrowNewException(WarHammer::binding::java::exception::EnvironmentException::UNINITIALIZED, this);

	if(this->_classes.find(className.getContent()) != this->_classes.end())
		return this->_classes[className.getContent()];

	WarHammer::util::String name = className.replace(".", "/");

	jclass JNIEnvironmentClass = this->_JNIEnvironment->FindClass(name.getCString());

	if(!JNIEnvironmentClass)
		ThrowNewException(WarHammer::binding::java::exception::EnvironmentException::INVALID_CLASS_NAME, this);

	WarHammer::util::SmartPointer<Class> clazz = new Class(JNIEnvironmentClass, this->_JNIEnvironment, name);
	this->_classes[className.getContent()] = clazz;

	return clazz;
}

JNIEnv* WarHammer::binding::java::Environment::getJNIEnvironment(void)
{
	if(!this->_JNIEnvironment)
		ThrowNewException(WarHammer::binding::java::exception::EnvironmentException::UNINITIALIZED, this);

	return this->_JNIEnvironment;
}

void WarHammer::binding::java::Environment::initialize(unsigned int version, WarHammer::io::Directory classDirectory)
{
	JavaVMInitArgs args;
	JavaVMOption options[1];

	args.version = version;
	args.nOptions = 1;
	options[0].optionString = const_cast<char*>(WarHammer::util::String::Format("-Djava.class.path=%s", classDirectory.getCompleteName().getCString()).getCString());
	args.options = options;
	args.ignoreUnrecognized = JNI_FALSE;
	JNI_CreateJavaVM(&this->_javaVM, (void**)&this->_JNIEnvironment, &args);
}
