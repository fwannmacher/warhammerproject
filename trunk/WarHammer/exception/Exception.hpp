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
 * Exception.hpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_exception_EXCEPTION_HPP__
#define __WarHammer_exception_EXCEPTION_HPP__

#include "util/StackTracer.hpp"

#define ThrowNewException(code, thrower) \
		{ \
			WarHammer::exception::util::StackTracer::Instance()->initializeNewStackTrace(code, #code); \
			WarHammer::exception::util::StackTracer::Instance()->appendStackTrace(code, WarHammer::util::String::Format("%s:%d", __FILE__, __LINE__)); \
			throw WarHammer::exception::Exception(code, thrower); \
		}

#define ThrowException(exception) \
		{ \
			WarHammer::exception::util::StackTracer::Instance()->appendStackTrace(exception.getCode(), WarHammer::util::String::Format("%s:%d", __FILE__, __LINE__)); \
			throw exception ; \
		}

#define ExtractStackTrace(exception) \
		WarHammer::exception::util::StackTracer::Instance()->getStackTrace(exception.getCode(), __FILE__, __LINE__)

#define GetExceptionUniqueIdentification() \
		__COUNTER__ + 1

namespace WarHammer
{
	namespace exception
	{

		/**
		 * @class WarHammer::exception::Exception
		 *
		 * @brief A generic exception class that has an exception code.
		 *
		 * WarHammer::exception::Exception is a generic concept of an exception. That has an integer code to identify the exception it is and a pointer to the thrower if it is set.
		 *
		 * @see WarHammer::exception::UniqueIdentificationGenerator
		 *
		 * @author Felipe Wannmacher
		 *
		 * @example exception.cpp
		 * Here is an example of the WarHammer::exception::Exception usage.
		 */
		class Exception
		{
		protected:
			/**
			 * @brief The exception's code.
			 *
			 * It is used to identify the exception was thrown.
			 */
			unsigned int _code;
			/**
			 * @brief The exception's thrower.
			 *
			 * It is used to identify who threw the exception.
			 */
			void* _thrower;
		public:
			/**
			 * @brief Custom constructor.
			 *
			 * A custom constructor that set the exception's code and the exception's thrower. If a thrower isn't set then it value will be NULL.
			 *
			 * @param code The exception's code.
			 * @param thrower The exception's thrower.
			 */
			Exception(unsigned int code, void* thrower);
			virtual ~Exception(void);
			/**
			 * @brief Get the exception's code.
			 *
			 * Get the code set in the thrown exception.
			 *
			 * @return The exception's code.
			 */
			unsigned int getCode(void);
			/**
			 * @brief Get the exception's thrower.
			 *
			 * Get the thrower who threw the exception.
			 *
			 * @return The exception's thrower.
			 */
			void* getThrower(void);
		};

	}
}

#endif
