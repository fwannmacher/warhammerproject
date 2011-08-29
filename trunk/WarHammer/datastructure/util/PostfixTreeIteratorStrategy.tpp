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
 * PostfixTreeIteratorStrategy.tpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_util_POSTFIXTREEITERATORSTRATEGY_HPP__

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::PostfixTreeIteratorStrategy(void)
{
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::~PostfixTreeIteratorStrategy(void)
{
}

template<typename TreeNodeSubclass, typename Content>
bool WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::hasNextNode(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename TreeNodeSubclass, typename Content>
bool WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::hasPreviousNode(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename TreeNodeSubclass, typename Content>
TreeNodeSubclass* WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::findNext(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	TreeNodeSubclass* next = iterator->getNextNode();

	if(!next->getParent())
		return NULL;
	if(next->getParent()->getChildren()[next->getParent()->getChildren().size() - 1] == next)
		return next->getParent();
	else
	{
		std::vector<TreeNodeSubclass*>& brothers = next->getParent()->getChildren();

		for(unsigned int i = 0; i < brothers.size() - 1; ++i)
			if(brothers[i] == next)
			{
				next = brothers[i + 1];

				while(next->hasChildren())
					next = next->getFirstChild();

				return next;
			}
	}

	return NULL;
}

template<typename TreeNodeSubclass, typename Content>
TreeNodeSubclass* WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::findPrevious(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	TreeNodeSubclass* previous = iterator->getPreviousNode();

	if(previous->hasChildren())
		return previous->getChildren()[previous->getChildren().size() - 1];
	else
	{
		TreeNodeSubclass* parent = NULL;

		while(previous->getParent())
		{
			parent = previous->getParent();
			std::vector<TreeNodeSubclass*>& brothers = parent->getChildren();

			for(unsigned int i = 1; i < brothers.size(); ++i)
				if(brothers[i] == previous)
					return brothers[i - 1];

			previous = parent;
		}
	}

	return NULL;
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::findFirst(TreeNodeSubclass* root)
{
	TreeNodeSubclass* first = root,
			* next = NULL;

	while(first->hasChildren())
		first = first->getFirstChild();

	if(first != root)
	{
		WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> iterator(NULL, first, NULL);
		next = this->findNext(&iterator);
	}

	return Iterator<TreeNodeSubclass, Content>(NULL, next, first);
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::findLast(TreeNodeSubclass* root)
{
	return Iterator<TreeNodeSubclass, Content>(root->hasChildren() ? root->getChildren()[root->getChildren().size() - 1] : NULL, NULL, root);
}

template<typename TreeNodeSubclass, typename Content>
Content WarHammer::datastructure::util::PostfixTreeIteratorStrategy<TreeNodeSubclass, Content>::getNodeContent(TreeNodeSubclass* node)
{
	return node->getContent();
}

#endif
