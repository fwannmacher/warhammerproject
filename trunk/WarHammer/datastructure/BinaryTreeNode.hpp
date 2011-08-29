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
 * BinaryTreeNode.hpp
 *
 *  Created on: May 27, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_datastructure_BINARYTREENODE_HPP__
#define __WarHammer_datastructure_BINARYTREENODE_HPP__

#include "TreeNode.hpp"

namespace WarHammer
{
	namespace datastructure
	{

		template<typename Content>
		class BinaryTreeNode: public TreeNode<Content, BinaryTreeNode<Content> >
		{
		private:
			unsigned int _firstChild,
						 _secondChild;
		public:
			BinaryTreeNode(void);
			BinaryTreeNode(Content content);
			virtual ~BinaryTreeNode(void);
			virtual void addChild(BinaryTreeNode* child);
			virtual bool hasChildren(void);
			virtual BinaryTreeNode* getFirstChild(void);
			virtual BinaryTreeNode* getSecondChild(void);
			virtual void setFirstChild(BinaryTreeNode* child);
			virtual void setSecondChild(BinaryTreeNode* child);
		};

	}
}

#include "BinaryTreeNode.tpp"

#endif
