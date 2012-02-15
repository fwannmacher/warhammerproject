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
 * Environment.hpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_binding_java_ENVIRONMENT_HPP__
#define __WarHammer_binding_java_ENVIRONMENT_HPP__

#include <jni.h>
#include <map>
#include "Class.hpp"
#include "../../io/Directory.hpp"
#include "../../util/Singleton.hpp"
#include "../../util/SmartPointer.hpp"

namespace WarHammer
{
	namespace binding
	{
		namespace java
		{

			class Class;

			class Environment: public WarHammer::util::Singleton<Environment>
			{
				friend class WarHammer::util::Singleton<Environment>;
			private:
				JavaVM* _javaVM;
				JNIEnv* _JNIEnvironment;
				std::map<std::string, WarHammer::util::SmartPointer<Class> > _classes;
			private:
				Environment(void);
			public:
				virtual ~Environment(void);
				WarHammer::util::SmartPointer<Class> getClass(WarHammer::util::String className);
				JNIEnv* getJNIEnvironment(void);
				void initialize(unsigned int version, WarHammer::io::Directory classDirectory);
			};

		}
	}
}

#endif
