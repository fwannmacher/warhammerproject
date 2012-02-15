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
 * StackTracer.cpp
 *
 *  Created on: Sep 16, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "StackTracer.hpp"

WarHammer::exception::util::StackTracer::StackTracer(void)
{
}

WarHammer::exception::util::StackTracer::~StackTracer(void)
{
	this->_stackTraces.clear();
}

WarHammer::util::String WarHammer::exception::util::StackTracer::_clearFilePath(WarHammer::util::String filePath)
{
	WarHammer::util::String cleanFilePath;
	std::vector<WarHammer::util::String> pathTokens = filePath.replace("\\", "/").replace("//", "/").split("/");

	for(unsigned int i = 0; i < pathTokens.size() - 1; ++i)
		if(pathTokens[i] == "..")
			continue;
		else if(pathTokens[i + 1] != "..")
			cleanFilePath += WarHammer::util::String::Format("%s/", pathTokens[i].getCString());
		else
			++i;

	cleanFilePath += pathTokens[pathTokens.size() - 1];

	return cleanFilePath;
}

void WarHammer::exception::util::StackTracer::appendStackTrace(unsigned int code, WarHammer::util::String trace)
{
	this->_stackTraces[code] += WarHammer::util::String::Format("\n%s", trace.getCString());
}

WarHammer::util::String WarHammer::exception::util::StackTracer::getStackTrace(unsigned int code, WarHammer::util::String fileName, unsigned int lineNumber)
{
	WarHammer::util::String stackTrace = WarHammer::util::String::Format("%s\n%s:%d", this->_stackTraces[code].getCString(), fileName.getCString(), lineNumber),
							cleanStackTrace;
	std::vector<WarHammer::util::String> stackTraceTokens = stackTrace.split("\n");

	cleanStackTrace = stackTraceTokens[0];

	for(unsigned int i = 1; i < stackTraceTokens.size(); ++i)
		cleanStackTrace += WarHammer::util::String::Format("\n%s", this->_clearFilePath(stackTraceTokens[i]).getCString());

	return cleanStackTrace;
}

void WarHammer::exception::util::StackTracer::initializeNewStackTrace(unsigned int code, WarHammer::util::String exceptionName)
{
	this->_stackTraces[code] = exceptionName;
}
