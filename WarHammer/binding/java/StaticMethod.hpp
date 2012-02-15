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
 * StaticMethod.hpp
 *
 *  Created on: Sep 22, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_binding_java_STATICMETHOD_HPP__
#define __WarHammer_binding_java_STATICMETHOD_HPP__

#include <jni.h>
#include "IMethod.hpp"
#include "Class.hpp"
#include "MethodParameterList.hpp"

namespace WarHammer
{
	namespace binding
	{
		namespace java
		{

			class Class;

			template<typename Return>
			class StaticMethod: public IMethod
			{
				friend class Class;
			protected:
				unsigned int _returnTypeCode;
				jmethodID _identification;
				JNIEnv* _JNIEnvironment;
				jclass _JNIEnvironmentClass;
				WarHammer::util::String _JNIEnvironmentReturnType;
			protected:
				StaticMethod(jmethodID identification, JNIEnv* JNIEnvironment, jclass JNIEnvironmentClass, unsigned int returnTypeCode, WarHammer::util::String JNIEnvironmentReturnType);
			public:
				virtual ~StaticMethod(void);
				virtual Return call(MethodParameterList methodParameterList) = 0;
				virtual WarHammer::util::String getJNIEnvironmentReturnType(void);
				virtual unsigned int getReturnTypeCode(void);
				virtual bool isStaticMethod(void);
			};

		}
	}
}

#include "StaticMethod.tpp"

#endif
