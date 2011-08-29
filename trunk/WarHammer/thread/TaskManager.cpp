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
 * TaskManager.cpp
 *
 *  Created on: Sep 23, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "TaskManager.hpp"
#include "util/TaskIdentificationGenerator.hpp"

WarHammer::thread::TaskManager::TaskManager(void)
{
}

WarHammer::thread::TaskManager::~TaskManager(void)
{
	while(!this->_undoneTasks.empty())
		this->_undoneTasks.pop();

	while(!this->_doneTasks.empty())
		this->_doneTasks.pop_back();
}

bool WarHammer::thread::TaskManager::_isTaskDone(unsigned int identification)
{
	bool isDone = false;

	this->_doneTasksMutex.lock();

	for(std::list<std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > >::iterator iterator = this->_doneTasks.begin(); iterator != this->_doneTasks.end(); ++iterator)
		if(iterator->first == identification)
		{
			isDone = true;
			this->_doneTasks.erase(iterator);
			break;
		}

	this->_doneTasksMutex.unlock();

	return isDone;
}

unsigned int WarHammer::thread::TaskManager::addTask(WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task)
{
	unsigned int identification = WarHammer::thread::util::TaskIdentificationGenerator::Instance()->generateIdentification();

	this->_undoneTasksMutex.lock();
	this->_undoneTasks.push(std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > >(identification, task));
	this->_undoneTasksMutex.unlock();

	return identification;
}

void WarHammer::thread::TaskManager::waitTask(unsigned int identification)
{
	while(!this->_isTaskDone(identification))
		this->_sleeper.sleep(3);
}

std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > WarHammer::thread::TaskManager::getUndoneTask(void)
{
	std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > task;

	this->_undoneTasksMutex.lock();

	if(!this->_undoneTasks.empty())
	{
		task = this->_undoneTasks.front();
		this->_undoneTasks.pop();
	}

	this->_undoneTasksMutex.unlock();

	return task;
}

void WarHammer::thread::TaskManager::setDoneTask(std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > task)
{
	this->_doneTasksMutex.lock();
	this->_doneTasks.push_front(task);
	this->_doneTasksMutex.unlock();
	WarHammer::thread::util::TaskIdentificationGenerator::Instance()->releaseIdentification(task.first);
}
