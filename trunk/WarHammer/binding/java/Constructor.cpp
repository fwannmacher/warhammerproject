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
 * Constructor.cpp
 *
 *  Created on: 22/09/2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Constructor.hpp"

#include <iostream>

WarHammer::binding::java::Constructor::Constructor(jmethodID identification, JNIEnv* JNIEnvironment, jclass JNIEnvironmentClass, unsigned int returnTypeCode, WarHammer::util::String JNIEnvironmentReturnType): WarHammer::binding::java::StaticMethod<jobject>(identification, JNIEnvironment, JNIEnvironmentClass, returnTypeCode, JNIEnvironmentReturnType)
{
}

WarHammer::binding::java::Constructor::~Constructor(void)
{
}

jobject WarHammer::binding::java::Constructor::call(MethodParameterList methodParameterList)
{
	std::vector<WarHammer::util::SmartPointer<Type> >& methodParameters = methodParameterList.getParameters();
	jvalue* parameters = new jvalue[methodParameters.size()];

	for(unsigned int i = 0; i < methodParameters.size(); ++i)
		parameters[i] = methodParameters[i]->getJNIEnvironmentValue();

	jobject JNIResult = this->_JNIEnvironment->NewObjectA(this->_JNIEnvironmentClass, this->_identification, parameters);

	delete[] parameters;

	return JNIResult;
}
