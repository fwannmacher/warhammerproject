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
 * ThreadPool.cpp
 *
 *  Created on: Apr 18, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "ThreadPool.hpp"

#include "exception/ThreadPoolException.hpp"
#include "../exception/Exception.hpp"

WarHammer::thread::ThreadPool::ThreadPool(void)
{
}

WarHammer::thread::ThreadPool::~ThreadPool(void)
{
	for(std::list<Thread*>::iterator iterator = this->_threads.begin(); iterator != this->_threads.end(); iterator = this->_threads.begin())
	{
		this->_threads.erase(iterator);
		delete (*iterator);
	}
}

void WarHammer::thread::ThreadPool::setNumberOfThreads(unsigned int numberOfThreads)
{
	if(!this->_threads.empty())
		throw WarHammer::exception::Exception(WarHammer::thread::exception::ThreadPoolException::THREAD_QUANTITY_ALREADY_SET, this);

	for(unsigned int i = 0; i < numberOfThreads; ++i)
	{
		Thread* thread = new Thread();
		thread->start();
		this->_threads.push_back(thread);
	}
}
