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
 * ParallelFor.tpp
 *
 *  Created on: Oct 16, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_loop_PARALLELFOR_HPP__

#include "../thread/TaskManager.hpp"

template<typename IndexType>
WarHammer::loop::ParallelFor<IndexType>::ParallelFor(unsigned int taskQuantity)
{
	this->_functor = NULL;
	this->_taskQuantity = taskQuantity;
}

template<typename IndexType>
WarHammer::loop::ParallelFor<IndexType>::~ParallelFor(void)
{
}

template<typename IndexType>
void WarHammer::loop::ParallelFor<IndexType>::_execute(IndexType begin, IndexType end)
{
	for(IndexType i = begin; i <= end; ++i)
		(*this->_functor)(i);
}

template<typename IndexType>
void WarHammer::loop::ParallelFor<IndexType>::execute(WarHammer::util::IParameterizedFunctor<void, IndexType>* functor, IndexType begin, IndexType end)
{
	this->_functor = functor;
	WarHammer::thread::TaskManager* taskManager = WarHammer::thread::TaskManager::Instance();
	IndexType position = 0,
			  size = end - begin + 1;
	std::vector<unsigned int> taskIdentifications;

	for(unsigned int i = 0; i < this->_taskQuantity - 1; ++i)
	{
		WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::loop::thread::ParallelForTask<IndexType>
		(
			this,
			begin + position,
			position + size / this->_taskQuantity - 1
		);
		taskIdentifications.push_back(taskManager->addTask(task));
		position += size / this->_threadQuantity;
	}

	WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task = new WarHammer::loop::thread::ParallelForTask<IndexType>
	(
		this,
		begin + position,
		end
	);
	taskIdentifications.push_back(taskManager->addTask(task));

	for(unsigned int i = 0; i < taskIdentifications.size(); ++i)
		taskManager->waitTask(taskIdentifications[i]);
}

#endif
