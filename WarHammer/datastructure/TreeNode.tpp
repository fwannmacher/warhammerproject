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
 * TreeNode.tpp
 *
 *  Created on: May 27, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_TREENODE_HPP__

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::TreeNode(void)
{
	this->_parent = NULL;
}

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::TreeNode(Content content)
{
	this->_parent = NULL;
	this->_content = content;
}

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::~TreeNode(void)
{
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::addChild(TreeNodeSubclass* child)
{
	child->setParent(static_cast<TreeNodeSubclass*>(this));
	this->_children.push_back(child);
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::removeChild(TreeNodeSubclass* child)
{
	for(unsigned int i = 0; i < this->_children.size(); ++i)
		if(this->_children[i] == child)
		{
			this->_children.erase(this->_children.begin() += i);
			break;
		}
}

template<typename Content, typename TreeNodeSubclass>
bool WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::hasChildren(void)
{
	return !this->_children.empty();
}

template<typename Content, typename TreeNodeSubclass>
TreeNodeSubclass* WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::getFirstChild(void)
{
	return this->_children.empty() ? NULL : this->_children[0];
}

template<typename Content, typename TreeNodeSubclass>
std::vector<TreeNodeSubclass*>& WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::getChildren(void)
{
	return this->_children;
}

template<typename Content, typename TreeNodeSubclass>
Content WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::getContent(void)
{
	return this->_content;
}

template<typename Content, typename TreeNodeSubclass>
TreeNodeSubclass* WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::getParent(void)
{
	return this->_parent;
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::setContent(Content content)
{
	this->_content = content;
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::TreeNode<Content, TreeNodeSubclass>::setParent(TreeNodeSubclass* parent)
{
	this->_parent = parent;
}

#endif
