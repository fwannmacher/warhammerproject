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
 * ExpressionInterpreterStringParser.tpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_util_EXPRESSIONINTERPRETERSTRINGPARSER_HPP__

template<typename ExpressionResult>
WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::ExpressionInterpreterStringParser(WarHammer::util::String expression)
{
	this->_expression = expression;
}

template<typename ExpressionResult>
WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::~ExpressionInterpreterStringParser(void)
{
}

template<typename ExpressionResult>
void WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::accept(WarHammer::util::IExpressionInterpreterComponentVisitor<ExpressionResult>* visitor)
{
	try
	{
		visitor->visit(this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

template<typename ExpressionResult>
WarHammer::util::String WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::getExpression(void)
{
	return this->_expression;
}

template<typename ExpressionResult>
ExpressionResult WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::getExpressionResult(void)
{
	return this->_expressionResult;
}

template<typename ExpressionResult>
void WarHammer::util::ExpressionInterpreterStringParser<ExpressionResult>::setExpressionResult(ExpressionResult expressionResult)
{
	this->_expressionResult = expressionResult;
}

#endif
