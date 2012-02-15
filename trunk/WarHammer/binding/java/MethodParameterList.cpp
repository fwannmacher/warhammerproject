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
 * MethodParameterList.cpp
 *
 *  Created on: Oct 03, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "MethodParameterList.hpp"

WarHammer::binding::java::MethodParameterList::MethodParameterList(void)
{
}

WarHammer::binding::java::MethodParameterList::~MethodParameterList(void)
{
	this->_parameters.clear();
}

void WarHammer::binding::java::MethodParameterList::addParameter(WarHammer::util::SmartPointer<WarHammer::binding::java::Type> parameter)
{
	this->_parameters.push_back(parameter);
}

std::vector<WarHammer::util::SmartPointer<WarHammer::binding::java::Type> >& WarHammer::binding::java::MethodParameterList::getParameters(void)
{
	return this->_parameters;
}

WarHammer::util::SmartPointer<WarHammer::binding::java::Type> WarHammer::binding::java::MethodParameterList::getReturnType(void)
{
	return this->_returnType;
}

void WarHammer::binding::java::MethodParameterList::setReturnType(WarHammer::util::SmartPointer<WarHammer::binding::java::Type> returnType)
{
	this->_returnType = returnType;
}
