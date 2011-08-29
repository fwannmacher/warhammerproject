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
 * IExpressionInterpreterComponentVisitor.hpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_util_EXPRESSIONINTERPRETERCOMPONENTVISITOR_HPP__
#define __WarHammer_util_EXPRESSIONINTERPRETERCOMPONENTVISITOR_HPP__

#include "ExpressionInterpreterSyntaxValidator.hpp"
#include "ExpressionInterpreterStringParser.hpp"

namespace WarHammer
{
	namespace util
	{

		template<typename ExpressionResult>
		class IExpressionInterpreterComponent;

		template<typename ExpressionResult>
		class ExpressionInterpreterSyntaxValidator;

		template<typename ExpressionResult>
		class ExpressionInterpreterStringParser;

		/**
		 * @interface WarHammer::util::IExpressionInterpreterComponentVisitor
		 *
		 * @brief An interface that represents the visitor design pattern for WarHammer::util::ExpressionInterpreter.
		 *
		 * WarHammer::util::IExpressionInterpreterComponentVisitor is an interface that represents the visitor design pattern for WarHammer::util::ExpressionInterpreter.
		 *
		 * @tparam ExpressionResult The result of the interpreted expression.
		 *
		 * @see WarHammer::util::ExpressionInterpreter
		 *
		 * @author Felipe Wannmacher
		 */
		template<typename ExpressionResult>
		class IExpressionInterpreterComponentVisitor
		{
		public:
			virtual ~IExpressionInterpreterComponentVisitor(void){};
			/**
			 * @brief Must be called by WarHammer::util::ExpressionInterpreterSyntaxValidator::accept method.
			 *
			 * Called by the WarHammer::util::ExpressionInterpreterSyntaxValidator::accept method, this method implements the algorithm of the expression validation.
			 *
			 * @param validator A pointer to expression syntax validator.
			 *
			 * @see WarHammer::util::ExpressionInterpreterSyntaxValidator
			 */
			virtual void visit(ExpressionInterpreterSyntaxValidator<ExpressionResult>* validator) = 0;
			/**
			 * @brief Must be called by WarHammer::util::ExpressionInterpreterStringParser::accept method.
			 *
			 * Called by the WarHammer::util::ExpressionInterpreterStringParser::accept method, this method implements the algorithm of the expression parse.
			 *
			 * @param parser A pointer to expression parser.
			 *
			 * @see WarHammer::util::ExpressionInterpreterStringParser
			 */
			virtual void visit(ExpressionInterpreterStringParser<ExpressionResult>* parser) = 0;
		};

	}
}

#endif
