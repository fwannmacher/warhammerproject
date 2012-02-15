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
 * File.cpp
 *
 *  Created on: Aug 10, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "File.hpp"

#include <cstdio>
#include "exception/FileException.hpp"
#include "../exception/Exception.hpp"

WarHammer::io::File::File(WarHammer::util::String completeEntryName, unsigned int openFlags): WarHammer::io::FileSystemEntry(completeEntryName)
{
	this->_closed = true;
	this->_file = NULL;
	this->_openFlags = "";
	this->_flags = openFlags;

	try
	{
		this->_open(completeEntryName, openFlags);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

WarHammer::io::File::~File(void)
{
	if(this->_file)
		fclose(this->_file);

	delete this->_file;
}

WarHammer::io::File* WarHammer::io::File::CreateFile(WarHammer::util::String completeFileName)
{
	if(completeFileName == "")
		ThrowNewException(WarHammer::io::exception::FileException::INVALID_NAME, NULL);

	FILE* file = fopen(completeFileName.getCString(), "w+");

	if(!file)
		ThrowNewException(WarHammer::io::exception::FileException::CREATE_ERROR, NULL);

	if(fclose(file))
		ThrowNewException(WarHammer::io::exception::FileException::CREATE_ERROR, NULL);

	try
	{
		return new File(completeFileName, File::WRITE);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

void WarHammer::io::File::_open(WarHammer::util::String completeEntryName, unsigned int openFlags)
{
	if(completeEntryName == "")
		ThrowNewException(WarHammer::io::exception::FileException::INVALID_NAME, this);

	if(this->_file)
	{
		fclose(this->_file);
		delete this->_file;
		this->_openFlags = "";
	}

	if(openFlags & File::READ)
		this->_openFlags += 'r';

	if(openFlags & File::WRITE)
		this->_openFlags += 'w';

	if(openFlags & File::APPEND)
		this->_openFlags += 'a';

	if(openFlags & File::BINARY)
		this->_openFlags += 'b';

	this->_file = fopen(this->getCompleteName().getCString(), this->_openFlags.getCString());

	if(!this->_file)
		ThrowNewException(WarHammer::io::exception::FileException::OPEN_ERROR, this);

	this->_closed = false;
}

void WarHammer::io::File::close(void)
{
	if(!this->_closed)
	{
		this->_closed = true;

		if(fclose(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::CLOSE_ERROR, this);
	}
}

void WarHammer::io::File::flush(void)
{
	if(this->_closed)
		ThrowNewException(WarHammer::io::exception::FileException::CLOSED, this);

	if(fflush(this->_file))
		ThrowNewException(WarHammer::io::exception::FileException::FLUSH_ERROR, this);
}

bool WarHammer::io::File::isDirectory(void)
{
	return false;
}

bool WarHammer::io::File::isFile(void)
{
	return true;
}

void WarHammer::io::File::open(void)
{
	if(this->_name == "")
		ThrowNewException(WarHammer::io::exception::FileException::INVALID_NAME, this);

	this->_file = freopen(this->getCompleteName().getCString(), this->_openFlags.getCString(), this->_file);

	if(!this->_file)
		ThrowNewException(WarHammer::io::exception::FileException::OPEN_ERROR, this);

	this->_closed = false;
}

WarHammer::util::String WarHammer::io::File::readAll(void)
{
	if(this->_closed)
		ThrowNewException(WarHammer::io::exception::FileException::CLOSED, this);

	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	unsigned int size = 0;
	unsigned int result = 0;

	fseek(this->_file, 0, SEEK_END);
	size = ftell(this->_file);
	rewind(this->_file);

	char* buffer = new char[size];
	result = fread(buffer, 1, size, this->_file);

	if(result != size)
		if(ferror(this->_file))
		{
			delete[] buffer;

			ThrowNewException(WarHammer::io::exception::FileException::READ_ERROR, this);
		}

	WarHammer::util::String content(buffer, result);
	delete[] buffer;

	return content;
}

bool WarHammer::io::File::readBoolean(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	int buffer;

	if(fscanf(this->_file, "%d", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return static_cast<bool>(buffer);
}

char* WarHammer::io::File::readBytes(unsigned int quantity)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	char* buffer = new char[quantity];
	buffer[0] = '\0';
	fread(buffer, 1, quantity, this->_file);

	if(ferror(this->_file))
	{
		delete[] buffer;

		ThrowNewException(WarHammer::io::exception::FileException::READ_ERROR, this);
	}

	if(buffer[0] == '\0' && feof(this->_file))
	{
		delete[] buffer;

		ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);
	}

	return buffer;
}

char WarHammer::io::File::readCharacter(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	char buffer;

	if(fscanf(this->_file, "%c", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

double WarHammer::io::File::readDouble(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	double buffer;

	if(fscanf(this->_file, "%lf", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

float WarHammer::io::File::readFloat(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	float buffer;

	if(fscanf(this->_file, "%f", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

int WarHammer::io::File::readInteger(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	int buffer;

	if(fscanf(this->_file, "%d", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

WarHammer::util::String WarHammer::io::File::readLine(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	char buffer[1024] = {'\0'};

	fgets(buffer, 1024, this->_file);

	if(buffer[0] == '\0' && feof(this->_file))
		ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

long WarHammer::io::File::readLong(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	long buffer;

	if(fscanf(this->_file, "%ld", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

short WarHammer::io::File::readShort(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	short buffer;

	if(fscanf(this->_file, "%hd", &buffer) == EOF)
		if(feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

void WarHammer::io::File::readStreamable(IStreamable* streamable)
{
	try
	{
		streamable->fromStream(this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

WarHammer::util::String WarHammer::io::File::readString(void)
{
	if(!(this->_flags & File::READ))
		ThrowNewException(WarHammer::io::exception::FileException::READ_MODE_ERROR, this);

	char buffer[256] = {'\0'};

	if(fscanf(this->_file, "%s", buffer) == EOF)
		if(buffer[0] == '\0' && feof(this->_file))
			ThrowNewException(WarHammer::io::exception::FileException::END_OF_FILE, this);

	return buffer;
}

void WarHammer::io::File::writeBoolean(bool value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%d", static_cast<int>(value)) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeBytes(char* value, unsigned int quantity)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fwrite(value, 1, quantity, this->_file) != quantity)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeCharacter(char value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%c", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeDouble(double value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%lf", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeFloat(float value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%f", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeInteger(int value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%d", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeLine(WarHammer::util::String value)
{
	try
	{
		this->writeString(value + '\n');
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

void WarHammer::io::File::writeLong(long value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%ld", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeShort(short value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fprintf(this->_file, "%hd", value) < 0)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}

void WarHammer::io::File::writeStreamable(IStreamable* streamable)
{
	try
	{
		streamable->toStream(this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

void WarHammer::io::File::writeString(WarHammer::util::String value)
{
	if(!(this->_flags & File::WRITE))
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_MODE_ERROR, this);

	if(fputs(value.getCString(), this->_file) == EOF)
		ThrowNewException(WarHammer::io::exception::FileException::WRITE_ERROR, this);
}
