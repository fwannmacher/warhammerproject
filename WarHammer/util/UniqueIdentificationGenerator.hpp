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
 * UniqueIdentificationGenerator.hpp
 *
 *  Created on: Sep 25, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_util_UNIQUEIDENTIFICATIONGENERATOR_HPP__
#define __WarHammer_util_UNIQUEIDENTIFICATIONGENERATOR_HPP__

#include <queue>
#include "Singleton.hpp"

namespace WarHammer
{
	namespace util
	{

		/**
		 * @class WarHammer::util::UniqueIdentificationGenerator
		 *
		 * @brief An generator of unique identifications.
		 *
		 * WarHammer::util::UniqueIdentificationGenerator is an generator of unique identification. It can be used to generates identifications where they need be unique for the functionality of the application.
		 *
		 * @author Felipe Wannmacher
		 */
		class UniqueIdentificationGenerator: public Singleton<UniqueIdentificationGenerator>
		{
			/**
			 * @brief Access to the protected constructor.
			 *
			 * Only the WarHammer::util::Singleton superclass has access to the class constructor.
			 */
			friend class Singleton<UniqueIdentificationGenerator>;
		protected:
			/**
			 * @brief The next unique identification that will be generated.
			 *
			 * A counter that will be incremented ever a new identification is created.
			 */
			unsigned int _nextIdentification;
			/**
			 * @brief A list with all released identifications.
			 *
			 * A queue with the identification that was released using the method WarHammer::util::UniqueIdentificationGenerator::releaseIdentification().
			 */
			std::queue<unsigned int> _releasedIdentifications;
		protected:
			UniqueIdentificationGenerator(void);
		public:
			virtual ~UniqueIdentificationGenerator(void);
			/**
			 * @brief Generates a new unique identification.
			 *
			 * Generates a new unique identification first looking in the released identifications list. If the list is empty then increment the identification counter an return it.
			 *
			 * @return A new unique identification.
			 */
			unsigned int generateIdentification(void);
			/**
			 * @brief Informs the passed identification was released.
			 *
			 * Informs the passed identification was released and can be used by the generator again.
			 *
			 * @param identification The identification that was released.
			 */
			void releaseIdentification(unsigned int identification);
		};

	}
}

#endif
