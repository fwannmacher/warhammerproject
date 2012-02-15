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
 * Object.hpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_binding_java_OBJECT_HPP__
#define __WarHammer_binding_java_OBJECT_HPP__

#include <jni.h>
#include "Class.hpp"
#include "Type.hpp"
#include "../../util/SmartPointer.hpp"

namespace WarHammer
{
	namespace binding
	{
		namespace java
		{

			class Class;

			class Object
			{
				friend class Class;
			private:
				jobject _JNIEnvironmentObject;
				JNIEnv* _JNIEnvironment;
				Class* _class;
			private:
				Object(jobject JNIEnvironmentObject, JNIEnv* JNIEnvironment, Class* clazz);
			public:
				virtual ~Object(void);
				jobject getJNIEnvironmentObject(void);
				float getFloatAttribute(WarHammer::util::String attributeName);
				bool callBolleanMethod(WarHammer::util::String methodName, ...);
				unsigned char callByteMethod(WarHammer::util::String methodName, ...);
				char callCharacterMethod(WarHammer::util::String methodName, ...);
				double callDoubleMethod(WarHammer::util::String methodName, ...);
				float callFloatMethod(WarHammer::util::String methodName, ...);
				int callIntegerMethod(WarHammer::util::String methodName, ...);
				long callLongMethod(WarHammer::util::String methodName, ...);
				WarHammer::util::SmartPointer<WarHammer::binding::java::Object> callObjectMethod(WarHammer::util::String methodName);
				WarHammer::util::SmartPointer<WarHammer::binding::java::Object> callObjectMethod(WarHammer::util::String methodName, MethodParameterList methodParameterList);
				short callShortMethod(WarHammer::util::String methodName, ...);
				WarHammer::util::String callStringMethod(WarHammer::util::String methodName);
				WarHammer::util::String callStringMethod(WarHammer::util::String methodName, MethodParameterList methodParameterList);
				void callVoidMethod(WarHammer::util::String methodName, ...);
			};

		}
	}
}

#endif
