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

//Create a class with constants that will be the exceptions you need handle.
class MyException
{
public:
	//Use the GetExceptionUniqueIdentification macro to generate an unique identification to your exception's constants.
	static const unsigned int EXCEPTION_CODE_1 = GetExceptionUniqueIdentification();
	static const unsigned int EXCEPTION_CODE_2 = GetExceptionUniqueIdentification();
};

int main(int argc, char** argv)
{
	try
	{
		//Then throw a WarHammer::exception::Exception passing the code you created.
		ThrowNewException(MyException::EXCEPTION_CODE_1, NULL); //Using the ThrowNewException macro you'll set the trace values for a future debug.
	}
	catch(WarHammer::exception::Exception exception)
	{
		//Now catch the exception and handle it based on the code that has.
		switch(exception.getCode())
		{
		case MyException::EXCEPTION_CODE_1:
		case MyException::EXCEPTION_CODE_2:
			std::cout << ExtractStackTrace(exception).getCString() << std::endl; //You may use the ExtractStackTrace to get the stack trace.			
			break;
		default:
			std::cout << "I don't know that code and I'll throw it up!" << std::endl;
			ThrowException(exception); //Use the ThrowException macro to set the trace logs on the exception.
			break;
		}
	}

	return 0;
}
