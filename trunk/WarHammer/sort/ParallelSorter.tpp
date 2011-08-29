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
 * ParallelSorter.tpp
 *
 *  Created on: Oct 5, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_sort_PARALLELSORTER_HPP__

#include <vector>
#include <utility>
#include "../thread/TaskManager.hpp"
#include "../util/SmartPointer.hpp"
#include "thread/ParallelSortTask.hpp"
#include "thread/ParallelSortContainerMergerTask.hpp"

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::ParallelSorter(unsigned int maxTaskQuantity, unsigned int minimumContainerSizePerTask): WarHammer::sort::Sorter<Subclass, Container, Content>()
{
	this->_maxTaskQuantity = maxTaskQuantity;
	this->_minimumContainerSizePerTask = minimumContainerSizePerTask;
	this->_taskQuantity = 0;
}

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::~ParallelSorter(void)
{
}

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
void WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::_sort(Container* container, unsigned int begin, unsigned int end)
{
	WarHammer::thread::TaskManager* taskManager = WarHammer::thread::TaskManager::Instance();
	unsigned int position = 0,
				 size = end - begin + 1;
	std::vector<unsigned int> taskIdentifications;

	for(unsigned int i = 0; i < this->_taskQuantity - 1; ++i)
	{
		WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::sort::thread::ParallelSortTask<SorterSubClass, Container, Content>
		(
			this->_sorter.getContent(),
			container,
			begin + position,
			position + size / this->_taskQuantity - 1,
			this->_order
		);
		taskIdentifications.push_back(taskManager->addTask(task));
		position += size / this->_taskQuantity;
	}

	WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::sort::thread::ParallelSortTask<SorterSubClass, Container, Content>
	(
		this->_sorter.getContent(),
		container,
		begin + position,
		end,
		this->_order
	);
	taskIdentifications.push_back(taskManager->addTask(task));

	for(unsigned int i = 0; i < taskIdentifications.size(); ++i)
		taskManager->waitTask(taskIdentifications[i]);
}

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
void WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::_join(Container* container, unsigned int begin, unsigned int end)
{
	unsigned int position = 0,
				 size = end - begin + 1,
				 oddThreadQuantityControl = 0;
	WarHammer::thread::TaskManager* taskManager = WarHammer::thread::TaskManager::Instance();
	Content* swapContainer = NULL,
		   * oldSwapContainer = new Content[size];
	std::vector<std::pair<unsigned int, unsigned int> > delimiters(this->_taskQuantity);

	for(unsigned int i = 0; i < size; ++i)
		oldSwapContainer[i] = (*container)[begin + i];

	for(unsigned int i = 0; i < this->_taskQuantity - 1; ++i)
	{
		delimiters[i].first = position;
		delimiters[i].second = position + size / this->_taskQuantity - 1;
		position += size / this->_taskQuantity;
	}

	delimiters[this->_taskQuantity - 1].first = position;
	delimiters[this->_taskQuantity - 1].second = size - 1;

	for(unsigned int taskQuantity = this->_taskQuantity; taskQuantity > 1; taskQuantity /= 2)
	{
		std::vector<unsigned int> taskIdentifications;
		swapContainer = new Content[size];
		oddThreadQuantityControl = taskQuantity % 2;

		for(unsigned int i = 0; i < taskQuantity - 2 - oddThreadQuantityControl; i += 2)
		{
			WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::sort::thread::ParallelSortContainerMergerTask<Content>
			(
				oldSwapContainer,
				swapContainer,
				&delimiters[i],
				&delimiters[i + 1],
				delimiters[i].first,
				delimiters[i + 1].second,
				this->_comparator,
				&this->_orderedContentArrayMerger
			);
			taskIdentifications.push_back(taskManager->addTask(task));
		}

		WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::sort::thread::ParallelSortContainerMergerTask<Content>
		(
			oldSwapContainer,
			swapContainer,
			&delimiters[taskQuantity - 2 - oddThreadQuantityControl],
			&delimiters[taskQuantity - 1 - oddThreadQuantityControl],
			delimiters[taskQuantity - 2 - oddThreadQuantityControl].first,
			delimiters[taskQuantity - 1 - oddThreadQuantityControl].second,
			this->_comparator,
			&this->_orderedContentArrayMerger
		);
		taskIdentifications.push_back(taskManager->addTask(task));

		for(unsigned int i = 0; i < taskIdentifications.size(); ++i)
			taskManager->waitTask(taskIdentifications[i]);

		for(unsigned int i = 0; i < taskQuantity / 2; ++i)
		{
			delimiters[i].second = delimiters[i + 1].second;
			delimiters.erase(delimiters.begin() + i + 1);
		}

		delete[] oldSwapContainer;

		oldSwapContainer = swapContainer;
		taskQuantity += oddThreadQuantityControl;
	}

	for(unsigned int i = 0; i < size; ++i)
		(*container)[begin + i] = oldSwapContainer[i];

	delete[] oldSwapContainer;
}

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
void WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::sort(Container* container, unsigned int begin, unsigned int end)
{
	this->sort(container, begin, end, WarHammer::sort::util::Comparator<Content>::CRESCENT);
}

template<typename Subclass, typename SorterSubClass, typename Container, typename Content>
void WarHammer::sort::ParallelSorter<Subclass, SorterSubClass, Container, Content>::sort(Container* container, unsigned int begin, unsigned int end, unsigned char order)
{
	unsigned int containerSize = begin + end + 1;

	this->_taskQuantity = containerSize / this->_minimumContainerSizePerTask <  this->_maxTaskQuantity ? containerSize / this->_minimumContainerSizePerTask : this->_maxTaskQuantity;
	Sorter<Subclass, Container, Content>::sort(container, begin, end, order);
	this->_join(container, begin, end);
}

#endif
