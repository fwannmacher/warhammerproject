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
 * BinaryTreeNode.tpp
 *
 *  Created on: May 27, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_BINARYTREENODE_HPP__

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>::BinaryTreeNode(void): WarHammer::datastructure::TreeNode<Content, WarHammer::datastructure::BinaryTreeNode<Content> >()
{
	this->_firstChild = 2;
	this->_secondChild = 2;
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>::BinaryTreeNode(Content content): WarHammer::datastructure::TreeNode<Content, WarHammer::datastructure::BinaryTreeNode<Content> >(content)
{
	this->_firstChild = 2;
	this->_secondChild = 2;
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>::~BinaryTreeNode(void)
{
}

template<typename Content>
void WarHammer::datastructure::BinaryTreeNode<Content>::addChild(WarHammer::datastructure::BinaryTreeNode<Content>* child)
{
}

template<typename Content>
bool WarHammer::datastructure::BinaryTreeNode<Content>::hasChildren(void)
{
	return !this->_children.empty();
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>* WarHammer::datastructure::BinaryTreeNode<Content>::getFirstChild(void)
{
	return this->_firstChild > 1 ? NULL : this->_children[this->_firstChild];
}

template<typename Content>
WarHammer::datastructure::BinaryTreeNode<Content>* WarHammer::datastructure::BinaryTreeNode<Content>::getSecondChild(void)
{
	return this->_secondChild > 1 ? NULL : this->_children[this->_secondChild];
}

template<typename Content>
void WarHammer::datastructure::BinaryTreeNode<Content>::setFirstChild(WarHammer::datastructure::BinaryTreeNode<Content>* child)
{
	child->setParent(this);

	if(this->_firstChild > 1)
	{
		if(this->_firstChild > this->_secondChild)
		{
			this->_children.push_back(this->_children[0]);
			this->_children[0] = child;
			this->_firstChild = 0;
			this->_secondChild = 1;
		}
		else
		{
			this->_children.push_back(child);
			this->_firstChild = 0;
		}
	}
	else
		this->_children[this->_firstChild] = child;
}

template<typename Content>
void WarHammer::datastructure::BinaryTreeNode<Content>::setSecondChild(WarHammer::datastructure::BinaryTreeNode<Content>* child)
{
	child->setParent(this);

	if(this->_secondChild > 1)
	{
		this->_children.push_back(child);
		this->_secondChild = this->_children.size() - 1;
	}
	else
		this->_children[this->_secondChild] = child;
}

#endif
