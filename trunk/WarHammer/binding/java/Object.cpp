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
 * Object.cpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Object.hpp"

#include "lang/Object.hpp"
#include "lang/String.hpp"

WarHammer::binding::java::Object::Object(jobject JNIEnvironmentObject, JNIEnv* JNIEnvironment, WarHammer::binding::java::Class* clazz)
{
	this->_JNIEnvironmentObject = JNIEnvironmentObject;
	this->_JNIEnvironment = JNIEnvironment;
	this->_class = clazz;
}

WarHammer::binding::java::Object::~Object(void)
{
}

jobject WarHammer::binding::java::Object::getJNIEnvironmentObject(void)
{
	return this->_JNIEnvironmentObject;
}

float WarHammer::binding::java::Object::getFloatAttribute(WarHammer::util::String attributeName)
{
	jfieldID identification = this->_JNIEnvironment->GetFieldID(this->_class->getJNIEnvironmentClass(), attributeName.getCString(), "F");

	return this->_JNIEnvironment->GetFloatField(this->_JNIEnvironmentObject, identification);
}

/*bool WarHammer::binding::java::Object::callBolleanMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	bool result = static_cast<Method<bool>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

unsigned char WarHammer::binding::java::Object::callByteMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	unsigned char result = static_cast<Method<unsigned char>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

char WarHammer::binding::java::Object::callCharacterMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	char result = static_cast<Method<char>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

double WarHammer::binding::java::Object::callDoubleMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	double result = static_cast<Method<double>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

float WarHammer::binding::java::Object::callFloatMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	float result = static_cast<Method<float>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

int WarHammer::binding::java::Object::callIntegerMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	int result = static_cast<Method<int>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}

long WarHammer::binding::java::Object::callLongMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	long result = static_cast<Method<long>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}*/

WarHammer::util::SmartPointer<WarHammer::binding::java::Object> WarHammer::binding::java::Object::callObjectMethod(WarHammer::util::String methodName)
{
	return this->callObjectMethod(methodName, MethodParameterList());
}

WarHammer::util::SmartPointer<WarHammer::binding::java::Object> WarHammer::binding::java::Object::callObjectMethod(WarHammer::util::String methodName, WarHammer::binding::java::MethodParameterList methodParameterList)
{
	if(!this->_class->isMethodLoaded(methodName))
	{
		methodParameterList.setReturnType(new WarHammer::binding::java::lang::Object());
		this->_class->loadMethod(methodName, methodParameterList);
	}

	Method<jobject>* method = static_cast<Method<jobject>*>(this->_class->getMethod(methodName).getContent());
	jobject JNIresult = method->call(this->_JNIEnvironmentObject, methodParameterList);
	WarHammer::util::String className = this->_class->getMethod(methodName)->getJNIEnvironmentReturnType().replace("/", ".");
	className = className.substring(1, className.length() - 2);

	return new Object(JNIresult, this->_JNIEnvironment, Environment::Instance()->getClass(className).getContent());
}

/*short WarHammer::binding::java::Object::callShortMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	short result = static_cast<Method<short>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);

	return result;
}*/

WarHammer::util::String WarHammer::binding::java::Object::callStringMethod(WarHammer::util::String methodName)
{
	return this->callStringMethod(methodName, MethodParameterList());
}

WarHammer::util::String WarHammer::binding::java::Object::callStringMethod(WarHammer::util::String methodName, WarHammer::binding::java::MethodParameterList methodParameterList)
{
	if(!this->_class->isMethodLoaded(methodName))
	{
		methodParameterList.setReturnType(new WarHammer::binding::java::lang::String());
		this->_class->loadMethod(methodName, methodParameterList);
	}

	jstring JNIResult = static_cast<jstring>(static_cast<Method<jobject>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, methodParameterList));
	const char* chars = Environment::Instance()->getJNIEnvironment()->GetStringUTFChars(JNIResult, 0);
	WarHammer::util::String result = chars;
	Environment::Instance()->getJNIEnvironment()->ReleaseStringUTFChars(JNIResult, chars);

	return result;
}

/*void WarHammer::binding::java::Object::callVoidMethod(WarHammer::util::String methodName, ...)
{
	va_list list;
	va_start(list, methodName);

	static_cast<Method<void>*>(this->_class->getMethod(methodName).getContent())->call(this->_JNIEnvironmentObject, list);

	va_end(list);
}*/

