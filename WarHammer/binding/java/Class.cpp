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
 * Class.cpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Class.hpp"

#include "BooleanMethod.hpp"
#include "Constructor.hpp"
#include "ObjectMethod.hpp"
#include "VoidMethod.hpp"
#include "VoidStaticMethod.hpp"
#include "enumeration/TypeCode.hpp"
#include "type/Void.hpp"

#include <iostream>

WarHammer::binding::java::Class::Class(jclass JNIEnvironmentClass, JNIEnv* JNIEnvironment, WarHammer::util::String className, bool isArray, unsigned int arrayDimensions): WarHammer::binding::java::Type(WarHammer::binding::java::enumeration::TypeCode::Object, isArray, arrayDimensions)
{
	this->_JNIEnvironmentClass = JNIEnvironmentClass;
	this->_JNIEnvironment = JNIEnvironment;
	this->_JNIEnvironmentType = WarHammer::util::String::Format("L%s;", className.getCString());
}

WarHammer::binding::java::Class::~Class(void)
{
	this->_methods.clear();
	this->_staticMethods.clear();
}

jclass WarHammer::binding::java::Class::getJNIEnvironmentClass(void)
{
	return this->_JNIEnvironmentClass;
}

WarHammer::util::SmartPointer<WarHammer::binding::java::IMethod> WarHammer::binding::java::Class::getMethod(WarHammer::util::String methodName)
{
	return this->_methods[methodName.getContent()];
}

WarHammer::util::SmartPointer<WarHammer::binding::java::IMethod> WarHammer::binding::java::Class::getStaticMethod(WarHammer::util::String methodName)
{
	return this->_staticMethods[methodName.getContent()];
}

bool WarHammer::binding::java::Class::isMethodLoaded(WarHammer::util::String methodName)
{
	return this->_methods.find(methodName.getContent()) !=  this->_methods.end();
}

bool WarHammer::binding::java::Class::isStaticMethodLoaded(WarHammer::util::String methodName)
{
	return this->_staticMethods.find(methodName.getContent()) !=  this->_staticMethods.end();
}

void WarHammer::binding::java::Class::loadMethod(WarHammer::util::String methodName, WarHammer::binding::java::MethodParameterList methodParameterList)
{
	IMethod* method = NULL;
	WarHammer::util::String parameters,
							signature;
	std::vector<WarHammer::util::SmartPointer<Type> >& methodParameters = methodParameterList.getParameters();

	for(unsigned int i = 0; i < methodParameters.size(); ++i)
		parameters += methodParameters[i]->getJNIEnvironmentType();

	signature = WarHammer::util::String::Format("(%s)%s", parameters.getCString(), methodParameterList.getReturnType()->getJNIEnvironmentType().getCString());

	jmethodID identification = this->_JNIEnvironment->GetMethodID(this->_JNIEnvironmentClass, methodName.getCString(), signature.getCString());

	switch(methodParameterList.getReturnType()->getTypeCode())
	{
	case WarHammer::binding::java::enumeration::TypeCode::Boolean:
		//method = new BooleanMethod(identification, this->_JNIEnvironment, returnType.getTypeCode(), returnType.getJNIEnvironmentType());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Byte:
		//method = new Method<jbyte>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Character:
		//method = new Method<jchar>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Double:
		//method = new Method<jdouble>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Float:
		//method = new Method<jfloat>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Integer:
		//method = new Method<jint>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Long:
		//method = new Method<jlong>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Short:
		//method = new Method<jshort>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Void:
		//method = new VoidMethod(identification, this->_JNIEnvironment, returnType.getTypeCode(), returnType.getJNIEnvironmentType());
		break;
	default:
		method = new ObjectMethod(identification, this->_JNIEnvironment, methodParameterList.getReturnType()->getTypeCode(), methodParameterList.getReturnType()->getJNIEnvironmentType());
		break;
	}

	this->_methods[methodName.getContent()] = method;
}

void WarHammer::binding::java::Class::loadStaticMethod(WarHammer::util::String methodName, WarHammer::binding::java::MethodParameterList methodParameterList)
{
	IMethod* method = NULL;
	WarHammer::util::String parameters,
							signature;
	std::vector<WarHammer::util::SmartPointer<Type> >& methodParameters = methodParameterList.getParameters();

	for(unsigned int i = 0; i < methodParameters.size(); ++i)
		parameters += methodParameters[i]->getJNIEnvironmentType();

	signature = WarHammer::util::String::Format("(%s)%s", parameters.getCString(), methodParameterList.getReturnType()->getJNIEnvironmentType().getCString());

	jmethodID identification = this->_JNIEnvironment->GetMethodID(this->_JNIEnvironmentClass, methodName.getCString(), signature.getCString());

	switch(methodParameterList.getReturnType()->getTypeCode())
	{
	case WarHammer::binding::java::enumeration::TypeCode::Boolean:
		//method = new BooleanMethod(identification, this->_JNIEnvironment, returnType.getTypeCode(), returnType.getJNIEnvironmentType());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Byte:
		//method = new Method<jbyte>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Character:
		//method = new Method<jchar>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Double:
		//method = new Method<jdouble>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Float:
		//method = new Method<jfloat>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Integer:
		//method = new Method<jint>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Long:
		//method = new Method<jlong>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Short:
		//method = new Method<jshort>(identification, this->_JNIEnvironment, returnType.getTypeCode());
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Void:
		if(methodName == "<init>")
			method = new Constructor(identification, this->_JNIEnvironment, this->_JNIEnvironmentClass, methodParameterList.getReturnType()->getTypeCode(), methodParameterList.getReturnType()->getJNIEnvironmentType());
		else
			method = new VoidStaticMethod(identification, this->_JNIEnvironment, this->_JNIEnvironmentClass, methodParameterList.getReturnType()->getTypeCode(), methodParameterList.getReturnType()->getJNIEnvironmentType());
		break;
	default:
		//method = new ObjectMethod(identification, this->_JNIEnvironment, returnType.getTypeCode(), returnType.getJNIEnvironmentType());
		break;
	}

	this->_staticMethods[methodName.getContent()] = method;
}

WarHammer::util::SmartPointer<WarHammer::binding::java::Object> WarHammer::binding::java::Class::newObject(void)
{
	return this->newObject(MethodParameterList());
}

WarHammer::util::SmartPointer<WarHammer::binding::java::Object> WarHammer::binding::java::Class::newObject(WarHammer::binding::java::MethodParameterList methodParameterList)
{
	if(!this->isStaticMethodLoaded("<init>"))
	{
		methodParameterList.setReturnType(new WarHammer::binding::java::type::Void());
		this->loadStaticMethod("<init>", methodParameterList);
	}

	jobject object = static_cast<Constructor*>(this->getStaticMethod("<init>").getContent())->call(methodParameterList);


	return new Object(object, this->_JNIEnvironment, this);
}
