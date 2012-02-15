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
 * String.hpp
 *
 *  Created on: Jun 10, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_util_STRING_HPP__
#define __WarHammer_util_STRING_HPP__

#include <string>
#include <vector>

namespace WarHammer
{
	namespace util
	{

		class String
		{
		public:
			static const unsigned int INVALID_INDEX = std::string::npos;
		private:
			std::string _content;
		public:
			static String ValueOf(int value);
			static String ValueOf(unsigned int value);
			static String ValueOf(short value);
			static String ValueOf(unsigned short value);
			static String ValueOf(long value);
			static String ValueOf(unsigned long value);
			static String ValueOf(char value);
			static String ValueOf(unsigned char value);
			static String ValueOf(bool value);
			static String ValueOf(float value);
			static String ValueOf(double value);
			static String Format(String format, ...);
		public:
			String& operator=(std::string& string);
			String& operator=(const std::string& string);
			String& operator=(String& string);
			String& operator=(const String& string);
			String& operator=(char* string);
			String& operator=(const char* string);
			String& operator=(char character);
			bool operator==(std::string& string);
			bool operator==(const std::string& string);
			bool operator==(String& string);
			bool operator==(const String& string);
			bool operator==(char* string);
			bool operator==(const char* string);
			bool operator!=(std::string& string);
			bool operator!=(const std::string& string);
			bool operator!=(String& string);
			bool operator!=(const String& string);
			bool operator!=(char* string);
			bool operator!=(const char* string);
			String operator+(std::string& string);
			String operator+(const std::string& string);
			String operator+(String& string);
			String operator+(const String& string);
			String operator+(char* string);
			String operator+(const char* string);
			String operator+(char character);
			String& operator+=(std::string& string);
			String& operator+=(const std::string& string);
			String& operator+=(String& string);
			String& operator+=(const String& string);
			String& operator+=(char* string);
			String& operator+=(const char* string);
			String& operator+=(char character);
			char operator[](unsigned int index);
		private:
			bool _isDelimiter(char character, std::string& delimiters);
		public:
			String(void);
			String(std::string string);
			String(String& string);
			String(const String& string);
			String(char* string);
			String(char* string, unsigned int size);
			String(const char* string);
			String(char character);
			virtual ~String(void);
			bool contains(String string);
			std::string getContent(void);
			const char* getCString(void);
			bool isEmpty(void);
			bool isNumber(void);
			unsigned int indexOf(String string, unsigned int startPosition = 0);
			unsigned int length(void);
			String replace(String oldString, String newString);
			std::vector<String> split(String delimiters);
			String substring(unsigned int begin, unsigned int length);
			String toLowerCase(void);
			String toUpperCase(void);
			String trim(void);
		};

	}
}

WarHammer::util::String operator+(const char* string, WarHammer::util::String& self);
WarHammer::util::String operator+(char character, WarHammer::util::String& self);

#endif
