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
 * Sorter.hpp
 *
 *  Created on: Oct 5, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_sort_SORTER_HPP__
#define __WarHammer_sort_SORTER_HPP__

#include "ISorter.hpp"
#include "util/Comparator.hpp"

namespace WarHammer
{
	namespace sort
	{

		template<typename Subclass, typename Container, typename Content>
		class Sorter: public ISorter<Container>
		{
		protected:
			unsigned char _order;
			WarHammer::sort::util::Comparator<Content>* _comparator;
		protected:
			void _swap(Container* container, unsigned int baseIndex, unsigned int swapIndex);
			virtual void _sort(Container* container, unsigned int begin, unsigned int end) = 0;
		public:
			Sorter(void);
			virtual ~Sorter(void);
			virtual void sort(Container* container, unsigned int begin, unsigned int end);
			virtual void sort(Container* container, unsigned int begin, unsigned int end, unsigned char order);
		};

	}
}

#include "Sorter.tpp"

#endif
