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
 * QuickSorter.tpp
 *
 *  Created on: Oct 5, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_QUICKSORTER_HPP__

#include "InsertionSorter.hpp"

template<typename Container, typename Content>
WarHammer::sort::QuickSorter<Container, Content>::QuickSorter(void): WarHammer::sort::Sorter<QuickSorter<Container, Content>, Container, Content>()
{
}

template<typename Container, typename Content>
WarHammer::sort::QuickSorter<Container, Content>::~QuickSorter(void)
{
}

template<typename Container, typename Content>
void WarHammer::sort::QuickSorter<Container, Content>::_quick(Container* container, unsigned int begin, unsigned int end)
{
	unsigned int i = 0,
				 j = 0;
	Content content;

	if((end - begin) > 4)
	{
		i = (end + begin) / 2;

		if(this->_comparator->rightComparison((*container)[begin], (*container)[i]))
			this->_swap(container, begin, i);

		if(this->_comparator->rightComparison((*container)[begin], (*container)[end]))
			this->_swap(container, begin, end);

		if(this->_comparator->rightComparison((*container)[i], (*container)[end]))
			this->_swap(container, i, end);

		j = end - 1;
		this->_swap(container, i, j);
		i = begin;
		content = (*container)[j];

		while(true)
		{
			while(this->_comparator->leftComparison((*container)[++i], content));

			while(this->_comparator->rightComparison((*container)[--j], content));

			if(j < i)
				break;

			this->_swap (container, i, j);
		}

		this->_swap(container, i, end - 1);
		this->_quick(container, begin, j);
		this->_quick(container, i + 1, end);
	}
}

template<typename Container, typename Content>
void WarHammer::sort::QuickSorter<Container, Content>::_sort(Container* container, unsigned int begin, unsigned int end)
{
	this->_quick(container, begin, end);
	InsertionSorter<Container, Content> insertionSorter;
	insertionSorter.sort(container, begin, end, this->_order);
}

#endif
