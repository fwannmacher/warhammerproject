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
 * File.hpp
 *
 *  Created on: Aug 10, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_io_FILE_HPP__
#define __WarHammer_io_FILE_HPP__

#include "FileSystemEntry.hpp"
#include "IInputStream.hpp"
#include "IOutputStream.hpp"

namespace WarHammer
{
	namespace io
	{

		class File: public FileSystemEntry, public IInputStream, public IOutputStream
		{
		public:
			static const unsigned int ASCII = 0x00;
			static const unsigned int BINARY = 0x01;
			static const unsigned int READ = 0x02;
			static const unsigned int WRITE = 0x04;
			static const unsigned int CREATE = 0x08;
			static const unsigned int APPEND = 0x10;
		private:
			bool _closed;
			FILE* _file;
			WarHammer::util::String _openFlags;
		public:
			File(void);
			File(WarHammer::util::String completeEntryName, unsigned int openFlags);
			virtual ~File(void);
			virtual void close(void);
			virtual void flush(void);
			virtual bool isDirectory(void);
			virtual void open(void);
			virtual void open(WarHammer::util::String completeEntryName, unsigned int openFlags);
			virtual WarHammer::util::String readAll(void);
			virtual bool readBoolean(void);
			virtual char* readBytes(unsigned int quantity);
			virtual char readCharacter(void);
			virtual double readDouble(void);
			virtual float readFloat(void);
			virtual int readInteger(void);
			virtual WarHammer::util::String readLine(void);
			virtual long readLong(void);
			virtual short readShort(void);
			virtual void readStreamable(IStreamable* streamable);
			virtual WarHammer::util::String readString(void);
			virtual void writeBoolean(bool value);
			virtual void writeBytes(char* value, unsigned int quantity);
			virtual void writeCharacter(char value);
			virtual void writeDouble(double value);
			virtual void writeFloat(float value);
			virtual void writeInteger(int value);
			virtual void writeLine(WarHammer::util::String value);
			virtual void writeLong(long value);
			virtual void writeShort(short value);
			virtual void writeStreamable(IStreamable* streamable);
			virtual void writeString(WarHammer::util::String value);
		};

	}
}

#endif
