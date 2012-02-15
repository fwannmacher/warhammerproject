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
 * Tree.tpp
 *
 *  Created on: May 27, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_TREE_HPP__

#include "util/PrefixTreeIteratorStrategy.hpp"
#include "util/TreeExpressionInterpreterVisitor.hpp"
#include "../exception/Exception.hpp"
#include "../util/ExpressionInterpreter.hpp"

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::Tree(void)
{
	this->_rootNode = NULL;
}

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::~Tree(void)
{
}

template<typename Content, typename TreeNodeSubclass>
std::vector<Content> WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::operator[](WarHammer::util::String expression)
{
	WarHammer::util::ExpressionInterpreter<std::vector<Content> > interpreter;
	WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass> visitor(this);

	try
	{
		return interpreter.interpret(expression, &visitor);
	}
	catch(WarHammer::exception::Exception exception)
	{
		ThrowException(exception);
	}
}

template<typename Content, typename TreeNodeSubclass>
TreeNodeSubclass* WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::getRootNode(void)
{
	return this->_rootNode;
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::setRootNode(TreeNodeSubclass* rootNode)
{
	this->_rootNode = rootNode;
}

template<typename Content, typename TreeNodeSubclass>
typename WarHammer::datastructure::IContainer<Content, TreeNodeSubclass>::Iterator WarHammer::datastructure::Tree<Content, TreeNodeSubclass>::getIterator(void)
{
	typename WarHammer::datastructure::IContainer<Content, TreeNodeSubclass>::Iterator iterator(this->_rootNode);
	iterator.setStrategy(new WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>());

	return iterator;
}

#endif
