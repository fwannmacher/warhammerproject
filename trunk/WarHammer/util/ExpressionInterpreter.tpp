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
 * ExpressionInterpreter.tpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_util_EXPRESSIONINTERPRETER_HPP__

#include "../exception/Exception.hpp"

template<typename ExpressionResult>
WarHammer::util::ExpressionInterpreter<ExpressionResult>::ExpressionInterpreter(void)
{
}

template<typename ExpressionResult>
WarHammer::util::ExpressionInterpreter<ExpressionResult>::~ExpressionInterpreter(void)
{
}

template<typename ExpressionResult>
ExpressionResult WarHammer::util::ExpressionInterpreter<ExpressionResult>::interpret(WarHammer::util::String expression, WarHammer::util::IExpressionInterpreterComponentVisitor<ExpressionResult>* visitor)
{
	ExpressionResult result;
	std::vector<IExpressionInterpreterComponent<ExpressionResult>*> components;

	components.push_back(new ExpressionInterpreterSyntaxValidator<ExpressionResult>(expression));
	components.push_back(new ExpressionInterpreterStringParser<ExpressionResult>(expression));

	try
	{
		for(unsigned int i = 0; i < components.size(); ++i)
		{
			components[i]->accept(visitor);
			result = components[i]->getExpressionResult();
			delete components[i];
		}
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	components.clear();

	return result;
}

#endif
