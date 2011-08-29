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
 * ExpressionInterpreterSyntaxValidator.hpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_util_EXPRESSIONINTERPRETERSYNTAXVALIDATOR_HPP__
#define __WarHammer_util_EXPRESSIONINTERPRETERSYNTAXVALIDATOR_HPP__

#include "IExpressionInterpreterComponent.hpp"
#include "String.hpp"

namespace WarHammer
{
	namespace util
	{

		template<typename ExpressionResult>
		class IExpressionInterpreterComponent;

		template<typename ExpressionResult>
		class IExpressionInterpreterComponentVisitor;

		template<typename ExpressionResult>
		class ExpressionInterpreterSyntaxValidator: public IExpressionInterpreterComponent<ExpressionResult>
		{
		private:
			bool _validExpressionValue;
			WarHammer::util::String _expression;
		public:
			ExpressionInterpreterSyntaxValidator(WarHammer::util::String expression);
			virtual ~ExpressionInterpreterSyntaxValidator(void);
			void accept(IExpressionInterpreterComponentVisitor<ExpressionResult>* visitor);
			WarHammer::util::String getExpression(void);
			ExpressionResult getExpressionResult(void);
			void setExpressionResult(ExpressionResult expressionResult);
		};

	}
}

#include "ExpressionInterpreterSyntaxValidator.tpp"

#endif
