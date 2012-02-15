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
 * Type.cpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Type.hpp"

WarHammer::binding::java::Type::Type(WarHammer::binding::java::enumeration::TypeCode::value typeCode, bool isArray, unsigned int arrayDimensions)
{
	this->_typeCode = typeCode;
	this->_array = isArray;
	this->_arrayDimensions = arrayDimensions;
	this->_setJNIEnvironmentType();
}

WarHammer::binding::java::Type::~Type(void)
{
}

void WarHammer::binding::java::Type::_setJNIEnvironmentType(void)
{
	switch(this->_typeCode)
	{
	case WarHammer::binding::java::enumeration::TypeCode::Boolean:
		this->_JNIEnvironmentType = "Z";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Byte:
		this->_JNIEnvironmentType = "B";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Character:
		this->_JNIEnvironmentType = "C";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Double:
		this->_JNIEnvironmentType = "D";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Float:
		this->_JNIEnvironmentType = "F";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Integer:
		this->_JNIEnvironmentType = "I";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Long:
		this->_JNIEnvironmentType = "J";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Short:
		this->_JNIEnvironmentType = "S";
		break;
	case WarHammer::binding::java::enumeration::TypeCode::Void:
		this->_JNIEnvironmentType = "V";
		break;
	default:
		break;
	}
}

WarHammer::binding::java::enumeration::TypeCode::value WarHammer::binding::java::Type::getTypeCode(void)
{
	return this->_typeCode;
}

WarHammer::util::String WarHammer::binding::java::Type::getJNIEnvironmentType(void)
{
	WarHammer::util::String arrayDimensions;

	if(this->_array)
		for(unsigned int i = 0; i < this->_arrayDimensions; ++i)
			arrayDimensions += '[';

	return WarHammer::util::String::Format("%s%s", arrayDimensions.getCString(), this->_JNIEnvironmentType.getCString());
}

jvalue WarHammer::binding::java::Type::getJNIEnvironmentValue(void)
{
	return this->_JNIEnvironmentValue;
}
