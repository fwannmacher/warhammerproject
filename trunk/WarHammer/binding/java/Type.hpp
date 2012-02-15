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
 * Type.hpp
 *
 *  Created on: Sep 21, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_binding_java_TYPE_HPP__
#define __WarHammer_binding_java_TYPE_HPP__

#include <jni.h>
#include "enumeration/TypeCode.hpp"
#include "../../util/String.hpp"

namespace WarHammer
{
	namespace binding
	{
		namespace java
		{

			class Type
			{
			protected:
				bool _array;
				unsigned int _arrayDimensions;
				WarHammer::binding::java::enumeration::TypeCode::value _typeCode;
				WarHammer::util::String _JNIEnvironmentType;
				jvalue _JNIEnvironmentValue;
			protected:
				void _setJNIEnvironmentType(void);
			public:
				Type(WarHammer::binding::java::enumeration::TypeCode::value typeCode, bool isArray = false, unsigned int arrayDimensions = 1);
				virtual ~Type(void);
				virtual WarHammer::binding::java::enumeration::TypeCode::value getTypeCode(void);
				virtual WarHammer::util::String getJNIEnvironmentType(void);
				virtual jvalue getJNIEnvironmentValue(void);
			};

		}
	}
}

#endif
