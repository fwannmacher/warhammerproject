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
 * FileException.hpp
 *
 *  Created on: Aug 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_io_exception_FILEEXCEPTION_HPP__
#define __WarHammer_io_exception_FILEEXCEPTION_HPP__

#include "../../exception/Exception.hpp"

namespace WarHammer
{
	namespace io
	{
		namespace exception
		{

			class FileException
			{
			public:
				static const unsigned int OPEN_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int READ_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int INVALID_NAME = GetExceptionUniqueIdentification();
				static const unsigned int CLOSE_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int CLOSED = GetExceptionUniqueIdentification();
				static const unsigned int FLUSH_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int WRITE_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int WRITE_MODE_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int READ_MODE_ERROR = GetExceptionUniqueIdentification();
				static const unsigned int END_OF_FILE = GetExceptionUniqueIdentification();
				static const unsigned int CREATE_ERROR = GetExceptionUniqueIdentification();
			};

		}
	}
}

#endif
