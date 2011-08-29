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
 * TreeExpressionInterpreterVisitor.hpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_datastructure_util_EXPRESSIONINTERPRETERSTRINGPARSER_HPP__
#define __WarHammer_datastructure_util_EXPRESSIONINTERPRETERSTRINGPARSER_HPP__

#include <vector>
#include "../KTree.hpp"
#include "../../util/IExpressionInterpreterComponentVisitor.hpp"
#include "../../util/String.hpp"

namespace WarHammer
{
	namespace datastructure
	{
		namespace util
		{

			template<typename Content, typename TreeNodeSubclass>
			class TreeExpressionInterpreterVisitor: public WarHammer::util::IExpressionInterpreterComponentVisitor<std::vector<Content> >
			{
			private:
				WarHammer::datastructure::Tree<Content, TreeNodeSubclass>* _tree;
			private:
				bool _isExpressionValid(WarHammer::util::String expression);
			private:
				void _parseExpressionNode(WarHammer::datastructure::KTreeNode<WarHammer::util::String>* currentNode, std::vector<Content>& result);
				std::vector<Content> _parseExpression(WarHammer::util::String expression);
			public:
				TreeExpressionInterpreterVisitor(WarHammer::datastructure::Tree<Content, TreeNodeSubclass>* tree);
				virtual ~TreeExpressionInterpreterVisitor(void);
				void visit(WarHammer::util::ExpressionInterpreterSyntaxValidator<std::vector<Content> >* validator);
				void visit(WarHammer::util::ExpressionInterpreterStringParser<std::vector<Content> >* parser);
			};

		}
	}
}

#include "TreeExpressionInterpreterVisitor.tpp"

#endif
