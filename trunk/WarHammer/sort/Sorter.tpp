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
 * Sorter.tpp
 *
 *  Created on: Oct 5, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_SORTER_HPP__

#include "util/CrescentComparator.hpp"
#include "util/DecrescentComparator.hpp"

template<typename Subclass, typename Container, typename Content>
WarHammer::sort::Sorter<Subclass, Container, Content>::Sorter(void)
{
	this->_order = WarHammer::sort::util::Comparator<Content>::CRESCENT;
	this->_comparator = new WarHammer::sort::util::CrescentComparator<Content>();
}

template<typename Subclass, typename Container, typename Content>
WarHammer::sort::Sorter<Subclass, Container, Content>::~Sorter(void)
{
	delete this->_comparator;
}

template<typename Subclass, typename Container, typename Content>
void WarHammer::sort::Sorter<Subclass, Container, Content>::_swap(Container* container, unsigned int baseIndex, unsigned int swapIndex)
{
	Content swapValue = (*container)[baseIndex];
	(*container)[baseIndex] = (*container)[swapIndex];
	(*container)[swapIndex] = swapValue;
}

template<typename Subclass, typename Container, typename Content>
void WarHammer::sort::Sorter<Subclass, Container, Content>::sort(Container* container, unsigned int begin, unsigned int end)
{
	this->sort(container, begin, end, WarHammer::sort::util::Comparator<Content>::CRESCENT);
}

template<typename Subclass, typename Container, typename Content>
void WarHammer::sort::Sorter<Subclass, Container, Content>::sort(Container* container, unsigned int begin, unsigned int end, unsigned char order)
{
	if(this->_order != order)
	{
		this->_order = order;
		delete this->_comparator;

		switch(order)
		{
		case WarHammer::sort::util::Comparator<Content>::DECRESCENT:
			this->_comparator = new WarHammer::sort::util::DecrescentComparator<Content>();
			break;
		case WarHammer::sort::util::Comparator<Content>::CRESCENT:
		default:
			this->_comparator = new WarHammer::sort::util::CrescentComparator<Content>();
			break;
		}
	}

	this->_sort(container, begin, end);
}

#endif
