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
 * TaskIdentificationGenerator.hpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_thread_util_TASKIDENTIFICATIONGENERATOR_HPP__
#define __WarHammer_thread_util_TASKIDENTIFICATIONGENERATOR_HPP__

#include "../../util/UniqueIdentificationGenerator.hpp"

namespace WarHammer
{
	namespace thread
	{
		namespace util
		{

			/**
			 * @class WarHammer::thread::util::TaskIdentificationGenerator
			 *
			 * @brief A generator of unique task codes.
			 *
			 * WarHammer::thread::util::TaskIdentificationGenerator is a generator of unique unique task codes.
			 *
			 * @see WarHammer::util::UniqueIdentificationGenerator
			 *
			 * @author Felipe Wannmacher
			 */
			class TaskIdentificationGenerator: public WarHammer::util::UniqueIdentificationGenerator
			{
				/**
				 * @brief Access to the private constructor.
				 *
				 * Only the superclass has access to the class constructor.
				 */
				friend class WarHammer::util::Singleton<TaskIdentificationGenerator>;
			private:
				TaskIdentificationGenerator(void);
			public:
				virtual ~TaskIdentificationGenerator(void);
			};

		}
	}
}

#endif
