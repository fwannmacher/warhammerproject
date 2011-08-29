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
 * ParallelSortContainerMergerTask.tpp
 *
 *  Created on: Oct 27, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_thread_PARALLELSORTCONTAINERMERGERTASK_HPP__

#include <utility>

template<typename Content>
WarHammer::sort::thread::ParallelSortContainerMergerTask<Content>::ParallelSortContainerMergerTask(Content* container, Content* swapContainer, std::pair<unsigned int, unsigned int>* firstContainerDelimiter, std::pair<unsigned int, unsigned int>* secondContainerDelimiter, unsigned int begin, unsigned int end, WarHammer::sort::util::Comparator<Content>* comparator, WarHammer::sort::util::OrderedContentArrayMerger<Content>* orderedContentArrayMerger)
{
	this->_container = container;
	this->_swapContainer = swapContainer;
	this->_firstContainerDelimiter = firstContainerDelimiter;
	this->_secondContainerDelimiter = secondContainerDelimiter;
	this->_begin = begin;
	this->_end = end;
	this->_comparator = comparator;
	this->_orderedContentArrayMerger = orderedContentArrayMerger;
}

template<typename Content>
WarHammer::sort::thread::ParallelSortContainerMergerTask<Content>::~ParallelSortContainerMergerTask(void)
{
}

template<typename Content>
bool WarHammer::sort::thread::ParallelSortContainerMergerTask<Content>::operator()(void)
{
	this->_orderedContentArrayMerger->mergeOrderedContentArrays
	(
		this->_container,
		this->_swapContainer,
		this->_firstContainerDelimiter,
		this->_secondContainerDelimiter,
		this->_begin,
		this->_end,
		this->_comparator
	);

	return true;
}

#endif
