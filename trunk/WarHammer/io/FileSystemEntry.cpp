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
 * FileSystemEntry.cpp
 *
 *  Created on: Aug 10, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "FileSystemEntry.hpp"

WarHammer::io::FileSystemEntry::FileSystemEntry(void)
{
	this->_path = "";
	this->_name = "";
	this->_flags = 0;
}

WarHammer::io::FileSystemEntry::~FileSystemEntry(void)
{
}

WarHammer::util::String WarHammer::io::FileSystemEntry::getName(void)
{
	return this->_name;
}

WarHammer::util::String WarHammer::io::FileSystemEntry::getPath(void)
{
	return this->_path;
}

WarHammer::util::String WarHammer::io::FileSystemEntry::getCompleteName(void)
{
	return this->_path + '/' + this->_name;
}

void WarHammer::io::FileSystemEntry::open(WarHammer::util::String completeEntryName, unsigned int openFlags)
{
	unsigned int index = 0;
	std::vector<WarHammer::util::String> path = completeEntryName.split("\\/");

	this->_path = "";
	this->_name = "";
	this->_flags = openFlags;

	for(index = 0; index < path.size() - 1; ++index)
	{
		if(this->_path != "")
			this->_path += '/';

		this->_path += path[index];
	}

	if(this->_path == "")
		this->_path = '.';

	this->_name = path[index];
}
