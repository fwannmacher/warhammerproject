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
 * Method.tpp
 *
 *  Created on: 22/09/2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_binding_java_METHOD_HPP__

#include "Type.hpp"

template<typename Return>
WarHammer::binding::java::Method<Return>::Method(jmethodID identification, JNIEnv* JNIEnvironment, unsigned int returnTypeCode, WarHammer::util::String JNIEnvironmentReturnType)
{
	this->_identification = identification;
	this->_JNIEnvironment = JNIEnvironment;
	this->_returnTypeCode = returnTypeCode;
	this->_JNIEnvironmentReturnType = JNIEnvironmentReturnType;
}

template<typename Return>
WarHammer::binding::java::Method<Return>::~Method(void)
{
}

template<typename Return>
WarHammer::util::String WarHammer::binding::java::Method<Return>::getJNIEnvironmentReturnType(void)
{
	return this->_JNIEnvironmentReturnType;
}

template<typename Return>
unsigned int WarHammer::binding::java::Method<Return>::getReturnTypeCode(void)
{
	return this->_returnTypeCode;
}

template<typename Return>
bool WarHammer::binding::java::Method<Return>::isStaticMethod(void)
{
	return false;
}

#endif
