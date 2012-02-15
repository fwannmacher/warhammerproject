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
 * String.cpp
 *
 *  Created on: Jun 10, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "String.hpp"

#include <cctype>
#include <sstream>
#include <cstdarg>
#include <cstdio>

WarHammer::util::String::String(void)
{
}

WarHammer::util::String::String(std::string string)
{
	this->_content = string;
}

WarHammer::util::String::String(WarHammer::util::String& string)
{
	this->_content = string._content;
}

WarHammer::util::String::String(const WarHammer::util::String& string)
{
	this->_content = string._content;
}

WarHammer::util::String::String(char* string)
{
	this->_content = string;
}

WarHammer::util::String::String(char* string, unsigned int size)
{
	this->_content = std::string(string, size);
}

WarHammer::util::String::String(const char* string)
{
	this->_content = string;
}

WarHammer::util::String::String(char character)
{
	this->_content = character;
}

WarHammer::util::String::~String(void)
{
}

WarHammer::util::String WarHammer::util::String::ValueOf(int value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(unsigned int value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(short value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(unsigned short value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(long value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(unsigned long value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(char value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << (int)value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(unsigned char value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << (unsigned int)value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(bool value)
{
	std::string string = "";

	if(value)
		string = "true";
	else
		string = "false";

	return String(string);
}

WarHammer::util::String WarHammer::util::String::ValueOf(float value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::ValueOf(double value)
{
	std::ostringstream stream(std::ostringstream::out);
	stream << value;

	return String(stream.str());
}

WarHammer::util::String WarHammer::util::String::Format(WarHammer::util::String format, ...)
{
	char buffer[1024];
	va_list arguments;
	va_start(arguments, format);
	vsprintf(buffer, format.getCString(), arguments);
	va_end(arguments);

	return String(buffer);
}

WarHammer::util::String& WarHammer::util::String::operator=(std::string& string)
{
	this->_content = string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(const std::string& string)
{
	this->_content = string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(WarHammer::util::String& string)
{
	this->_content = string._content;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(const WarHammer::util::String& string)
{
	this->_content = string._content;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(char* string)
{
	this->_content = string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(const char* string)
{
	this->_content = string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator=(char character)
{
	this->_content = character;

	return *this;
}

bool WarHammer::util::String::operator==(std::string& string)
{
	return this->_content == string;
}

bool WarHammer::util::String::operator==(const std::string& string)
{
	return this->_content == string;
}

bool WarHammer::util::String::operator==(WarHammer::util::String& string)
{
	return this->_content == string._content;
}

bool WarHammer::util::String::operator==(const WarHammer::util::String& string)
{
	return this->_content == string._content;
}

bool WarHammer::util::String::operator==(char* string)
{
	return this->_content == string;
}

bool WarHammer::util::String::operator==(const char* string)
{
	return this->_content == string;
}

bool WarHammer::util::String::operator!=(std::string& string)
{
	return this->_content != string;
}

bool WarHammer::util::String::operator!=(const std::string& string)
{
	return this->_content != string;
}

bool WarHammer::util::String::operator!=(WarHammer::util::String& string)
{
	return this->_content != string._content;
}

bool WarHammer::util::String::operator!=(const WarHammer::util::String& string)
{
	return this->_content != string._content;
}

bool WarHammer::util::String::operator!=(char* string)
{
	return this->_content != string;
}

bool WarHammer::util::String::operator!=(const char* string)
{
	return this->_content != string;
}

WarHammer::util::String WarHammer::util::String::operator+(std::string& string)
{
	return String(this->_content + string);
}

WarHammer::util::String WarHammer::util::String::operator+(const std::string& string)
{
	return String(this->_content + string);
}

WarHammer::util::String WarHammer::util::String::operator+(WarHammer::util::String& string)
{
	return String(this->_content + string._content);
}

WarHammer::util::String WarHammer::util::String::operator+(const WarHammer::util::String& string)
{
	return String(this->_content + string._content);
}

WarHammer::util::String WarHammer::util::String::operator+(char* string)
{
	return String(this->_content + string);
}

WarHammer::util::String WarHammer::util::String::operator+(const char* string)
{
	return String(this->_content + string);
}

WarHammer::util::String WarHammer::util::String::operator+(char character)
{
	return String(this->_content + character);
}

WarHammer::util::String& WarHammer::util::String::operator+=(std::string& string)
{
	this->_content += string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(const std::string& string)
{
	this->_content += string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(WarHammer::util::String& string)
{
	this->_content += string._content;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(const WarHammer::util::String& string)
{
	this->_content += string._content;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(char* string)
{
	this->_content += string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(const char* string)
{
	this->_content += string;

	return *this;
}

WarHammer::util::String& WarHammer::util::String::operator+=(char character)
{
	this->_content += character;

	return *this;
}

char WarHammer::util::String::operator[](unsigned int index)
{
	return this->_content[index];
}

bool WarHammer::util::String::_isDelimiter(char character, std::string& delimiters)
{
	bool isDelimiterValue = false;

	for(unsigned int i = 0; i < delimiters.size(); ++i)
		if(character == delimiters[i])
		{
			isDelimiterValue = true;
			break;
		}

	return isDelimiterValue;
}

bool WarHammer::util::String::contains(WarHammer::util::String string)
{
	return this->_content.find(string._content, 0) != String::INVALID_INDEX;
}

const char* WarHammer::util::String::getCString(void)
{
	return this->_content.c_str();
}

std::string WarHammer::util::String::getContent(void)
{
	return this->_content;
}

bool WarHammer::util::String::isEmpty(void)
{
	return this->_content.empty();
}

bool WarHammer::util::String::isNumber(void)
{
	bool isNumberValue = true;

	for(unsigned int i = 0; i < this->_content.size(); ++i)
		if(!isdigit(this->_content[i]))
		{
			isNumberValue = false;
			break;
		}

	return isNumberValue;
}

unsigned int WarHammer::util::String::indexOf(WarHammer::util::String string, unsigned int startPosition)
{
	return this->_content.find(string._content, startPosition);
}

unsigned int WarHammer::util::String::length(void)
{
	return this->_content.size();
}

WarHammer::util::String WarHammer::util::String::replace(WarHammer::util::String oldString, WarHammer::util::String newString)
{
	std::string content = this->_content;

	for(unsigned int i = 0; i < content.size(); ++i)
		if(content[i] == oldString[0])
		{
			bool matches = true;

			for(unsigned int j = 0; j < oldString.length(); ++j)
				if(content[i + j] != oldString[j])
				{
					matches = false;
					break;
				}

			if(matches)
				content.replace(i, oldString.length(), newString.getCString());
		}

	return String(content);
}

std::vector<WarHammer::util::String> WarHammer::util::String::split(WarHammer::util::String delimiters)
{
	std::vector<String> tokens;
	std::string token = "";

	for(unsigned int i = 0; i < this->_content.size(); ++i)
		if(!this->_isDelimiter(this->_content[i], delimiters._content))
			token += this->_content[i];
		else if(!token.empty())
		{
			tokens.push_back(token);
			token = "";
		}

	if(!token.empty())
		tokens.push_back(token);

	return tokens;
}

WarHammer::util::String WarHammer::util::String::substring(unsigned int begin, unsigned int length)
{
	return String(this->_content.substr(begin, length));
}

WarHammer::util::String WarHammer::util::String::toLowerCase(void)
{
	String string(this->_content);

	for(unsigned int i = 0; i < string._content.size(); ++i)
		string._content[i] = tolower(string._content[i]);

	return string;
}

WarHammer::util::String WarHammer::util::String::toUpperCase(void)
{
	String string(this->_content);

	for(unsigned int i = 0; i < string._content.size(); ++i)
		string._content[i] = toupper(string._content[i]);

	return string;
}

WarHammer::util::String WarHammer::util::String::trim(void)
{
	unsigned int leadIndex = 0,
				 trailIndex = 0;

	for(; isspace(this->_content[leadIndex]) && leadIndex < this->_content.size(); ++leadIndex);

	for(trailIndex = this->_content.size(); isspace(this->_content[trailIndex - 1]) && trailIndex > 0; --trailIndex);

	return String(this->_content.substr(leadIndex, trailIndex - leadIndex));
}

WarHammer::util::String operator+(const char* string, WarHammer::util::String& self)
{
	return WarHammer::util::String(string + self.getContent());
}

WarHammer::util::String operator+(char character, WarHammer::util::String& self)
{
	return WarHammer::util::String(character + self.getContent());
}
