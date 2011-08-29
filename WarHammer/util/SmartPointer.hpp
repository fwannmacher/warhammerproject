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
 * SmartPointer.hpp
 *
 *  Created on: Oct 11, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_util_SMARTPOINTER_HPP__
#define __WarHammer_util_SMARTPOINTER_HPP__

#include <memory>

namespace WarHammer
{
	namespace util
	{

		template<typename Content>
		class SmartPointer
		{
		private:
			Content* _content;
			unsigned int* _referenceCounter;
		private:
			void _addReference(unsigned int* referenceCounter);
			void _removeReference(void);
		public:
			SmartPointer& operator=(Content* content);
			SmartPointer& operator=(SmartPointer& pointer);
			SmartPointer& operator=(const SmartPointer& pointer);
			SmartPointer& operator=(std::auto_ptr<Content>& pointer);
			SmartPointer& operator=(const std::auto_ptr<Content>& pointer);
			/**
			 *
			 * @return
			 *
			 * @exception WarHammer::exception::PointerException::NULL_POINTER if the content pointer is not set.
			 */
			Content& operator*(void);
			/**
			 *
			 * @return
			 *
			 * @exception WarHammer::exception::PointerException::NULL_POINTER if the content pointer is not set.
			 */
			Content* operator->(void);
		public:
			SmartPointer(void);
			SmartPointer(Content* content);
			SmartPointer(SmartPointer& pointer);
			SmartPointer(const SmartPointer& pointer);
			SmartPointer(std::auto_ptr<Content>& pointer);
			SmartPointer(const std::auto_ptr<Content>& pointer);
			virtual ~SmartPointer(void);
			Content* releaseContent(void);
			Content* getContent(void);
		};

	}
}

#include "SmartPointer.tpp"

#endif
