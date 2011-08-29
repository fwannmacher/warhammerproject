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
 * TypeReflector.cpp
 *
 *  Created on: 02/08/2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "TypeReflector.hpp"

#include "exception/TypeReflectorException.hpp"

WarHammer::reflect::TypeReflector::TypeReflector(void)
{
}

WarHammer::reflect::TypeReflector::~TypeReflector(void)
{
	this->_types.clear();
}

void WarHammer::reflect::TypeReflector::registerType(WarHammer::util::String typeAlias, IType* type)
{
	if(this->_types.find(typeAlias.getContent()) != this->_types.end())
		throw WarHammer::exception::Exception(WarHammer::reflect::exception::TypeReflectorException::TYPE_ALREADY_REGISTERED, this);

	this->_types[typeAlias.getContent()] = type;
}

void* WarHammer::reflect::TypeReflector::newInstanceOf(WarHammer::util::String typeAlias)
{
	if(this->_types.find(typeAlias.getContent()) == this->_types.end())
		throw WarHammer::exception::Exception(WarHammer::reflect::exception::TypeReflectorException::UNREGISTERED_TYPE, this);

	return this->_types[typeAlias.getContent()]->newInstance();
}
