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
 * InfixBinaryTreeIteratorStrategy.tpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_util_INFIXBINARYTREEITERATORSTRATEGY_HPP__

template<typename Content>
WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::InfixBinaryTreeIteratorStrategy(void)
{
}

template<typename Content>
WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::~InfixBinaryTreeIteratorStrategy(void)
{
}

template<typename Content>
bool WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::hasNextNode(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename Content>
bool WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::hasPreviousNode(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>* WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::findNext(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator)
{
	WarHammer::datastructure::BinaryTreeNode<Content>* next = iterator->getNextNode();

	if(next->getSecondChild())
	{
		next = next->getSecondChild();

		while(next->getFirstChild())
			next = next->getFirstChild();

		return next;
	}
	else if(!next->getParent())
		return NULL;
	else if(next->getParent()->getFirstChild() == next)
		return next->getParent();
	else if(next->getParent()->getSecondChild() == next && next->getParent()->getParent() && next->getParent()->getParent()->getSecondChild() == next->getParent())
		return NULL;
	else
		return next->getParent()->getParent();

	return NULL;
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>* WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::findPrevious(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator)
{
	WarHammer::datastructure::BinaryTreeNode<Content>* previous = iterator->getPreviousNode();

	if(previous->getParent())
		return previous->getParent();

	//TODO implementation

	return NULL;
}

template<typename Content>
WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content > WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::findFirst(WarHammer::datastructure::BinaryTreeNode<Content>* root)
{
	WarHammer::datastructure::BinaryTreeNode<Content>* first = root;

	while(first->hasChildren())
		first = first->getFirstChild();

	return Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >(NULL, first->getParent(), first);
}

template<typename Content>
WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content > WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::findLast(WarHammer::datastructure::BinaryTreeNode<Content>* root)
{
	WarHammer::datastructure::BinaryTreeNode<Content>* last = root;

	while(last->getSecondChild())
		last = last->getSecondChild();

	return Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >(last->getParent(), NULL, last);
}

template<typename Content>
Content WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy<Content>::getNodeContent(WarHammer::datastructure::BinaryTreeNode<Content>* node)
{
	return node->getContent();
}

#endif
