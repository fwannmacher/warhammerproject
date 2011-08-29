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
 *  Created on: Jul 19, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include <iostream>
#include "../WarHammer/exception/Exception.hpp"
#include "../WarHammer/exception/util/ExceptionIdentificationGenerator.hpp"

//Create a class with constants that will be the exceptions you need handle.
class MyException
{
public:
	static const unsigned int EXCEPTION_CODE_1;
	static const unsigned int EXCEPTION_CODE_2;
};

//Use the WarHammer::exception::ExceptionIdentificationGenerator to generate an unique identification to your constants.
const unsigned int MyException::EXCEPTION_CODE_1 = WarHammer::exception::ExceptionIdentificationGenerator::Instance()->generateIdentification();
const unsigned int MyException::EXCEPTION_CODE_2 = WarHammer::exception::ExceptionIdentificationGenerator::Instance()->generateIdentification();

int main(int argc, char** argv)
{
	try
	{
		//Then throw a WarHammer::exception::Exception passing the code you created.
		throw WarHammer::exception::Exception(MyException::EXCEPTION_CODE_1);
	}
	catch(WarHammer::exception::Exception exception)
	{
		//Now catch the exception and handle it based on the code that has.
		if(exception.getCode() == MyException::EXCEPTION_CODE_1)
			std::cout << "Catch an exception with code MyException::EXCEPTION_CODE_1[" << MyException::EXCEPTION_CODE_1 << "]" << std::endl;
		else if(exception.getCode() == MyException::EXCEPTION_CODE_2)
			std::cout << "Catch an exception with code MyException::EXCEPTION_CODE_2[" << MyException::EXCEPTION_CODE_2 << "]" << std::endl;
		else
		{
			std::cout << "I don't know that code and I'll throw it up!" << std::endl;

			throw exception;
		}

	}

	return 0;
}
