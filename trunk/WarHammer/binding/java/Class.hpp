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
 * Class.hpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_binding_java_CLASS_HPP__
#define __WarHammer_binding_java_CLASS_HPP__

#include <jni.h>
#include <map>
#include "Environment.hpp"
#include "Method.hpp"
#include "MethodParameterList.hpp"
#include "Object.hpp"
#include "Type.hpp"
#include "../../util/SmartPointer.hpp"
#include "../../util/String.hpp"

namespace WarHammer
{
	namespace binding
	{
		namespace java
		{

			class Environment;
			template<typename Return>
			class Method;
			class Object;

			class Class: public Type
			{
				friend class Environment;
			protected:
				jclass _JNIEnvironmentClass;
				JNIEnv* _JNIEnvironment;
				std::map<std::string, WarHammer::util::SmartPointer<IMethod> > _methods;
				std::map<std::string, WarHammer::util::SmartPointer<IMethod> > _staticMethods;
			protected:
				Class(jclass JNIEnvironmentClass, JNIEnv* JNIEnvironment, WarHammer::util::String className, bool isArray = false, unsigned int arrayDimensions = 1);
			public:
				virtual ~Class(void);
				jclass getJNIEnvironmentClass(void);
				WarHammer::util::SmartPointer<IMethod> getMethod(WarHammer::util::String methodName);
				WarHammer::util::SmartPointer<IMethod> getStaticMethod(WarHammer::util::String methodName);
				bool isMethodLoaded(WarHammer::util::String methodName);
				bool isStaticMethodLoaded(WarHammer::util::String methodName);
				void loadMethod(WarHammer::util::String methodName, MethodParameterList methodParameterList);
				void loadStaticMethod(WarHammer::util::String methodName, MethodParameterList methodParameterList);
				WarHammer::util::SmartPointer<Object> newObject(void);
				WarHammer::util::SmartPointer<Object> newObject(MethodParameterList methodParameterList);
			};

		}
	}
}

#endif
