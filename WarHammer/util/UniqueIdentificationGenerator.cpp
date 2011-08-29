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
 * UniqueIdentificationGenerator.cpp
 *
 *  Created on: Sep 25, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "UniqueIdentificationGenerator.hpp"

WarHammer::util::UniqueIdentificationGenerator::UniqueIdentificationGenerator(void)
{
	this->_nextIdentification = 1;
}

WarHammer::util::UniqueIdentificationGenerator::~UniqueIdentificationGenerator(void)
{
}

unsigned int WarHammer::util::UniqueIdentificationGenerator::generateIdentification(void)
{
	unsigned int identification = 0;

	if(!this->_releasedIdentifications.empty())
	{
		identification = this->_releasedIdentifications.front();
		this->_releasedIdentifications.pop();
	}

	if(!identification)
		identification = this->_nextIdentification++;

	return identification;
}

void WarHammer::util::UniqueIdentificationGenerator::releaseIdentification(unsigned int identification)
{
	if(identification < this->_nextIdentification)
		this->_releasedIdentifications.push(identification);
}
