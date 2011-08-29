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
 * Thread.cpp
 *
 *  Created on: Dec 29, 2008
 *      Author: Felipe Wannmacher
 *     License: LGPL - http://www.gnu.org/licenses/lgpl.html
 */

#include "Thread.hpp"

WarHammer::thread::Thread::Thread(void)
{
	this->_suspend = false;
	this->_exit = false;
	this->_sleep = 0;
	this->_thread = NULL;
}

WarHammer::thread::Thread::~Thread(void)
{
	if(!this->_exit)
	{
		this->_exitMutex.lock();
		this->_exit = true;
		this->_exitMutex.unlock();
		this->wait();
	}
}

WarHammer::thread::Mutex* WarHammer::thread::Thread::getSuspendMutex(void)
{
	return &(this->_suspendMutex);
}

WarHammer::thread::Mutex* WarHammer::thread::Thread::getSleepMutex(void)
{
	return &(this->_sleepMutex);
}

WarHammer::thread::Mutex* WarHammer::thread::Thread::getExitMutex(void)
{
	return &(this->_exitMutex);
}

void WarHammer::thread::Thread::start(void)
{
	if(!this->_thread)
		this->_thread = SDL_CreateThread(Thread::_threadFunction, this);
	else
	{
		this->_suspendMutex.lock();
		this->_suspend = false;
		this->_suspendMutex.unlock();
		this->_sleepMutex.lock();
		this->_sleep = 0;
		this->_sleepMutex.unlock();
	}
}

void WarHammer::thread::Thread::suspend(void)
{
	this->_suspendMutex.lock();
	this->_suspend = true;
	this->_suspendMutex.unlock();
}

void WarHammer::thread::Thread::sleep(unsigned long milliseconds)
{
	this->_sleepMutex.lock();
	this->_sleep = milliseconds;
	this->_sleepMutex.unlock();
}

void WarHammer::thread::Thread::wait(void)
{
	if(this->_thread)
		SDL_WaitThread(this->_thread, NULL);
}

int WarHammer::thread::Thread::_threadFunction(void* thread)
{
	Thread* t = static_cast<Thread*>(thread);
	bool suspend = false, exit = false, taskComplete = false;

	while(true)
	{
		t->_suspendMutex.lock();
		suspend = t->_suspend;
		t->_suspendMutex.unlock();

		if(!suspend)
		{
			t->_sleepMutex.lock();

			if(t->_sleep)
			{
				t->_sleeper.sleep(t->_sleep);
				t->_sleep = 0;
			}

			t->_sleepMutex.unlock();
			t->_exitMutex.lock();

			if(!t->_task.second.getContent())
				t->_task = TaskManager::Instance()->getUndoneTask();

			if(!t->_task.second.getContent())
				t->sleep(3);
			else
				taskComplete = (*t->_task.second)();

			t->_exitMutex.unlock();
		}

		if(taskComplete)
		{
			TaskManager::Instance()->setDoneTask(t->_task);
			t->_task = std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > >();
			taskComplete = false;
		}

		if(!exit)
		{
			t->_exitMutex.lock();
			exit = t->_exit;
			t->_exitMutex.unlock();
		}
		else
		{
			t->_exit = true;
			break;
		}
	}

	return 0;
}
