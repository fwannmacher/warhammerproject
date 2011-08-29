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
 * Thread.hpp
 *
 *  Created on: Dec 29, 2008
 *      Author: Felipe Wannmacher
 *     License: LGPL - http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_thread_THREAD_HPP__
#define __WarHammer_thread_THREAD_HPP__

#include <SDL/SDL_thread.h>
#include "Mutex.hpp"
#include "TaskManager.hpp"
#include "util/Sleeper.hpp"
#include "../util/SmartPointer.hpp"
#include "../util/IFunctor.hpp"

namespace WarHammer
{
	namespace thread
	{

		class Thread
		{
		private:
			unsigned long _sleep;
			bool _suspend,
				 _exit;
			SDL_Thread* _thread;
			std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > _task;
			Mutex _suspendMutex,
				  _sleepMutex,
				  _exitMutex;
			WarHammer::thread::util::Sleeper _sleeper;
		private:
			static int _threadFunction(void* thread);
		public:
			Thread(void);
			virtual ~Thread(void);
			Mutex* getSuspendMutex(void);
			Mutex* getSleepMutex(void);
			Mutex* getExitMutex(void);
			void start(void);
			void suspend(void);
			void sleep(unsigned long milliseconds);
			void wait(void);
		};

	}
}

#endif
