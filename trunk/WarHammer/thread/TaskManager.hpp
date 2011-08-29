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
 * TaskManager.hpp
 *
 *  Created on: Sep 23, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_thread_TASKMANAGER_HPP__
#define __WarHammer_thread_TASKMANAGER_HPP__

#include <queue>
#include <list>
#include <utility>
#include "Mutex.hpp"
#include "util/Sleeper.hpp"
#include "../util/Singleton.hpp"
#include "../util/SmartPointer.hpp"
#include "../util/IFunctor.hpp"

namespace WarHammer
{
	namespace thread
	{

		class TaskManager: public WarHammer::util::Singleton<TaskManager>
		{
			friend class WarHammer::util::Singleton<TaskManager>;
		private:
			std::queue<std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > > _undoneTasks;
			std::list<std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > > _doneTasks;
			Mutex _undoneTasksMutex,
				  _doneTasksMutex;
			WarHammer::thread::util::Sleeper _sleeper;
		private:
			TaskManager(void);
			bool _isTaskDone(unsigned int identification);
		public:
			virtual ~TaskManager(void);
			unsigned int addTask(WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > task);
			void waitTask(unsigned int identification);
			std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > getUndoneTask(void);
			void setDoneTask(std::pair<unsigned int, WarHammer::util::SmartPointer<WarHammer::util::IFunctor<bool> > > task);
		};

	}
}

#endif
