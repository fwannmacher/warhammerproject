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
 * Directory.hpp
 *
 *  Created on: Sep 12, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_io_DIRECTORY_HPP__
#define __WarHammer_io_DIRECTORY_HPP__

#include <dirent.h>
#include "FileSystemEntry.hpp"
#include "File.hpp"

namespace WarHammer
{
	namespace io
	{

		class Directory: public FileSystemEntry
		{
		public:
			static Directory* CreateDirectory(WarHammer::util::String completeDirectoryName);
		private:
			bool _closed,
				 _entriesLoaded;
			DIR* _directory;
			std::vector<Directory*> _directories;
			std::vector<FileSystemEntry*> _entries;
			std::vector<File*> _files;
		private:
			void _loadEntries(void);
			void _open(WarHammer::util::String completeEntryName, bool recursive);
		public:
			Directory(void);
			Directory(WarHammer::util::String completeEntryName, bool recursive = false);
			virtual ~Directory(void);
			void close(void);
			Directory* createDirectory(WarHammer::util::String directoryName);
			File* createFile(WarHammer::util::String fileName);
			std::vector<Directory*> getDirectories(void);
			std::vector<FileSystemEntry*> getEntries(void);
			std::vector<File*> getFiles(void);
			bool isDirectory(void);
			bool isFile(void);
			void open(void);
		};

	}
}

#endif
