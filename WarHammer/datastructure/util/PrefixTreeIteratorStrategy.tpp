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
 * PrefixTreeIteratorStrategy.tpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_util_PREFIXTREEITERATORSTRATEGY_HPP__

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::PrefixTreeIteratorStrategy(void)
{
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::~PrefixTreeIteratorStrategy(void)
{
}

template<typename TreeNodeSubclass, typename Content>
bool WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::hasNextNode(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename TreeNodeSubclass, typename Content>
bool WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::hasPreviousNode(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	return iterator->getCurrentNode() != NULL;
}

template<typename TreeNodeSubclass, typename Content>
TreeNodeSubclass* WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::findNext(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	TreeNodeSubclass* next = iterator->getNextNode();

	if(next->hasChildren())
		return next->getFirstChild();
	else
	{
		TreeNodeSubclass* parent = NULL;

		while(next->getParent())
		{
			parent = next->getParent();
			std::vector<TreeNodeSubclass*>& brothers = parent->getChildren();

			for(unsigned int i = 0; i < brothers.size() - 1; ++i)
				if(brothers[i] == next)
					return brothers[i + 1];

			next = parent;
		}
	}

	return NULL;
}

template<typename TreeNodeSubclass, typename Content>
TreeNodeSubclass* WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::findPrevious(WarHammer::datastructure::Iterator<TreeNodeSubclass, Content>* iterator)
{
	TreeNodeSubclass* previous = iterator->getPreviousNode();

	if(!previous->getParent())
		return NULL;
	else if(previous->getParent()->getFirstChild() == previous)
		return previous->getParent();
	else
	{
		std::vector<TreeNodeSubclass*>& brothers = previous->getParent()->getChildren();

		for(unsigned int i = 1; i < brothers.size(); ++i)
			if(brothers[i] == previous)
			{
				previous = brothers[i - 1];

				while(previous->hasChildren())
					previous = previous->getChildren()[previous->getChildren().size() - 1];

				return previous;
			}
	}

	return NULL;
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::findFirst(TreeNodeSubclass* root)
{
	return Iterator<TreeNodeSubclass, Content>(NULL, root->getFirstChild(), root);
}

template<typename TreeNodeSubclass, typename Content>
WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::findLast(TreeNodeSubclass* root)
{
	TreeNodeSubclass* last = root,
					* previous = NULL;

	while(last->hasChildren())
		last = last->getChildren()[last->getChildren().size() - 1];

	if(last != root)
	{
		WarHammer::datastructure::Iterator<TreeNodeSubclass, Content> iterator(last, NULL, NULL);
		previous = this->findPrevious(&iterator);
	}

	return Iterator<TreeNodeSubclass, Content>(previous, NULL, last);
}

template<typename TreeNodeSubclass, typename Content>
Content WarHammer::datastructure::util::PrefixTreeIteratorStrategy<TreeNodeSubclass, Content>::getNodeContent(TreeNodeSubclass* node)
{
	return node->getContent();
}

#endif
