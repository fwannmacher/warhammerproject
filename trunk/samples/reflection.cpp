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
 * exception.cpp
 *
 *  Created on: Aug 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include <iostream>
#include "../WarHammer/exception/Exception.hpp"
#include "../WarHammer/reflect/TypeReflector.hpp"
#include "../WarHammer/reflect/exception/TypeReflectorException.hpp"

//A class that you want reflect.
class MyClass
{
public:
	void foo(void)
	{
		std::cout << "MyClass: foo" << std::endl;
	}
};

int main(int argc, char** argv)
{
	try
	{
		//Register your class to reflect it in the future.
		WarHammer::common::TypeReflector::Instance()->registerType("MyClass", TypeOf(MyClass));

		//You can register a basic type too.
		WarHammer::common::TypeReflector::Instance()->registerType("int", TypeOf(int));

		//You can instantiate that class any time you want using the provided alias.
		WarHammer::util::SmartPointer<MyClass> myClass = static_cast<MyClass*>(WarHammer::common::TypeReflector::Instance()->newInstanceOf("MyClass"));

		//Now you can use your instantiated class.
		myClass->foo();
	}
	catch(WarHammer::exception::Exception exception)
	{
		//Here you can see the exceptions thrown by the TypeReflector.
		if(exception.getCode() == WarHammer::common::exception::TypeReflectorException::TYPE_ALREADY_REGISTERED)
			std::cout << "The type is already registered!" << std::endl;
		else if(exception.getCode() == WarHammer::common::exception::TypeReflectorException::UNREGISTERED_TYPE)
			std::cout << "The type is not registered!" << std::endl;
	}

	return 0;
}
