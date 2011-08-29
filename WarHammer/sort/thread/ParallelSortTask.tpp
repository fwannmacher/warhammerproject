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
 * ParallelSortTask.tpp
 *
 *  Created on: Sep 27, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_thread_PARALLELSORTTASK_HPP__

template<typename SorterSubclass, typename Container, typename Content>
WarHammer::sort::thread::ParallelSortTask<SorterSubclass, Container, Content>::ParallelSortTask(WarHammer::sort::Sorter<SorterSubclass, Container, Content>* sorter, Container* container, unsigned int begin, unsigned int end, unsigned char order)
{
	this->_sorter = sorter;
	this->_container = container;
	this->_begin = begin;
	this->_end = end;
	this->_order = order;
}

template<typename SorterSubclass, typename Container, typename Content>
WarHammer::sort::thread::ParallelSortTask<SorterSubclass, Container, Content>::~ParallelSortTask(void)
{
}

template<typename SorterSubclass, typename Container, typename Content>
bool WarHammer::sort::thread::ParallelSortTask<SorterSubclass, Container, Content>::operator()(void)
{
	this->_sorter->sort(this->_container, this->_begin, this->_end, this->_order);

	return true;
}

#endif
