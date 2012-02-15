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
 * Directory.cpp
 *
 *  Created on: Sep 12, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Directory.hpp"

#include <cstdio>
#include <dir.h>
#include "exception/DirectoryException.hpp"
#include "../exception/Exception.hpp"

WarHammer::io::Directory::Directory(WarHammer::util::String completeEntryName, bool recursive): WarHammer::io::FileSystemEntry(completeEntryName)
{
	this->_closed = true;
	this->_entriesLoaded = false;
	this->_directory = NULL;

	try
	{
		this->_open(completeEntryName, recursive);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

WarHammer::io::Directory::~Directory(void)
{
	if(this->_directory)
		delete this->_directory;

	for(unsigned int i = 0; i < this->_entries.size(); ++i)
		delete this->_entries[i];

	this->_directories.clear();
	this->_files.clear();
}

WarHammer::io::Directory* WarHammer::io::Directory::CreateDirectory(WarHammer::util::String completeDirectoryName)
{
	if(completeDirectoryName == "")
		ThrowNewException(WarHammer::io::exception::DirectoryException::INVALID_NAME, NULL);

	if(mkdir(completeDirectoryName.getCString()) < 0)
		ThrowNewException(WarHammer::io::exception::DirectoryException::CREATE_ERROR, NULL);

	try
	{
		return new Directory(completeDirectoryName);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

void WarHammer::io::Directory::_loadEntries(void)
{
	try
	{
		dirent* entryInformation = NULL;

		while((entryInformation = readdir(this->_directory)))
		{
			WarHammer::util::String entryName = WarHammer::util::String::Format("%s/%s", this->getCompleteName().getCString(), entryInformation->d_name);

			if(WarHammer::util::String(entryInformation->d_name) == "." || WarHammer::util::String(entryInformation->d_name) == "..")
				continue;

			if(opendir(entryName.getCString()))
			{
				Directory* directory = new Directory(entryName);
				this->_directories.push_back(directory);
				this->_entries.push_back(directory);
			}
			else
			{
				File* file = new File(entryName, File::READ);
				this->_files.push_back(file);
				this->_entries.push_back(file);
			}
		}
	}
	catch (WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}

	this->_entriesLoaded = true;
}

void WarHammer::io::Directory::_open(WarHammer::util::String completeEntryName, bool recursive)
{
	if(completeEntryName == "")
		ThrowNewException(WarHammer::io::exception::DirectoryException::INVALID_NAME, this);

	this->_directory = opendir(completeEntryName.getCString());

	if(!this->_directory)
		ThrowNewException(WarHammer::io::exception::DirectoryException::OPEN_ERROR, this);

	this->_closed = false;

	if(recursive)
		try
		{
			this->_loadEntries();
		}
		catch (WarHammer::exception::Exception exception)
		{
			ThrowException(exception);
		}
}

void WarHammer::io::Directory::close(void)
{
	if(!this->_closed)
	{
		this->_closed = true;

		if(closedir(this->_directory) < 0)
			ThrowNewException(WarHammer::io::exception::DirectoryException::CLOSE_ERROR, this);

		try
		{
			for(unsigned int i = 0; i < this->_entries.size(); ++i)
				this->_entries[i]->close();
		}
		catch (WarHammer::exception::Exception exception)
		{
			ThrowException(exception);
		}

		this->_entries.clear();
		this->_directories.clear();
		this->_files.clear();
		this->_entriesLoaded = false;
	}
}

WarHammer::io::Directory* WarHammer::io::Directory::createDirectory(WarHammer::util::String directoryName)
{
	Directory* directory = NULL;

	try
	{
		directory = Directory::CreateDirectory(WarHammer::util::String::Format("%s/%s", this->getCompleteName().getCString(), directoryName.getCString()));
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}

	if(this->_entriesLoaded)
	{
		this->_directories.push_back(directory);
		this->_entries.push_back(directory);
	}

	return directory;
}

WarHammer::io::File* WarHammer::io::Directory::createFile(WarHammer::util::String fileName)
{
	File* file = NULL;

	try
	{
		file = File::CreateFile(WarHammer::util::String::Format("%s/%s", this->getCompleteName().getCString(), fileName.getCString()).getCString());
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}

	if(this->_entriesLoaded)
	{
		this->_files.push_back(file);
		this->_entries.push_back(file);
	}

	return file;
}

std::vector<WarHammer::io::Directory*> WarHammer::io::Directory::getDirectories(void)
{
	if(!this->_entriesLoaded)
		try
		{
			this->_loadEntries();
		}
		catch (WarHammer::exception::Exception exception)
		{
			ThrowException(exception);
		}

	return this->_directories;
}

std::vector<WarHammer::io::FileSystemEntry*> WarHammer::io::Directory::getEntries(void)
{
	if(!this->_entriesLoaded)
		try
		{
			this->_loadEntries();
		}
		catch (WarHammer::exception::Exception exception)
		{
			ThrowException(exception);
		}

	return this->_entries;
}

std::vector<WarHammer::io::File*> WarHammer::io::Directory::getFiles(void)
{
	if(!this->_entriesLoaded)
		try
		{
			this->_loadEntries();
		}
		catch (WarHammer::exception::Exception exception)
		{
			ThrowException(exception);
		}

	return this->_files;
}

bool WarHammer::io::Directory::isDirectory(void)
{
	return true;
}

bool WarHammer::io::Directory::isFile(void)
{
	return false;
}

void WarHammer::io::Directory::open(void)
{
	try
	{
		this->_open(this->getCompleteName(), true);
	}
	catch (WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}
