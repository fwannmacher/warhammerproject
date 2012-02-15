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
 * StackTracer.hpp
 *
 *  Created on: Sep 16, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_exception_util_STACKTRACER_HPP__
#define __WarHammer_exception_util_STACKTRACER_HPP__

#include <map>
#include "../../util/Singleton.hpp"
#include "../../util/String.hpp"

namespace WarHammer
{
	namespace exception
	{
		namespace util
		{

			class StackTracer: public WarHammer::util::Singleton<StackTracer>
			{
				friend class WarHammer::util::Singleton<StackTracer>;
			private:
				std::map<unsigned int, WarHammer::util::String> _stackTraces;
			private:
				StackTracer(void);
				WarHammer::util::String _clearFilePath(WarHammer::util::String filePath);
			public:
				virtual ~StackTracer(void);
				void appendStackTrace(unsigned int code, WarHammer::util::String trace);
				WarHammer::util::String getStackTrace(unsigned int code, WarHammer::util::String fileName, unsigned int lineNumber);
				void initializeNewStackTrace(unsigned int code, WarHammer::util::String exceptionName);
			};

		}
	}
}

#endif
