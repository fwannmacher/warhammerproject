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
 * QuickSorterFactory.tpp
 *
 *  Created on: Apr 15, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_QUICKSORTERFACTORY_HPP__

#include "QuickSorter.hpp"
#include "ParallelQuickSorter.hpp"

template<typename Container, typename Content>
WarHammer::sort::QuickSorterFactory<Container, Content>::QuickSorterFactory(unsigned int maxTaskQuantity, unsigned int minimumContainerSizePerTask): WarHammer::sort::SorterFactory<Container>::SorterFactory(maxTaskQuantity, minimumContainerSizePerTask)
{
}

template<typename Container, typename Content>
WarHammer::sort::QuickSorterFactory<Container, Content>::~QuickSorterFactory(void)
{
}

template<typename Container, typename Content>
WarHammer::sort::ISorter<Container>* WarHammer::sort::QuickSorterFactory<Container, Content>::_createSorter(void)
{
	return new QuickSorter<Container, Content>();
}

template<typename Container, typename Content>
WarHammer::sort::ISorter<Container>* WarHammer::sort::QuickSorterFactory<Container, Content>::_createParallelSorter(void)
{
	return new ParallelQuickSorter<Container, Content>(this->_maxTaskQuantity, this->_minimumContainerSizePerTask);
}

#endif
