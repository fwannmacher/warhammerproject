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
 * IntegerArray.cpp
 *
 *  Created on: Sep 23, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "IntegerArray.hpp"

#include "../Environment.hpp"

WarHammer::binding::java::type::IntegerArray::IntegerArray(int value[], unsigned int arraySize, unsigned int arrayDimensions): WarHammer::binding::java::Type(WarHammer::binding::java::enumeration::TypeCode::Integer, true, arrayDimensions)
{
	this->_JNIEnvironmentArray = WarHammer::binding::java::Environment::Instance()->getJNIEnvironment()->NewIntArray(arraySize);
	WarHammer::binding::java::Environment::Instance()->getJNIEnvironment()->SetIntArrayRegion(this->_JNIEnvironmentArray, 0, arraySize, (jint*)value);
	this->_JNIEnvironmentValue.l = this->_JNIEnvironmentArray;
	this->_value = value;
}

WarHammer::binding::java::type::IntegerArray::~IntegerArray(void)
{
	WarHammer::binding::java::Environment::Instance()->getJNIEnvironment()->ReleaseIntArrayElements(this->_JNIEnvironmentArray, (jint*)this->_value, 0);
}
