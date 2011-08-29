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
 * InfixBinaryTreeIteratorStrategy.hpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_datastructure_util_INFIXBINARYTREEITERATORSTRATEGY_HPP__
#define __WarHammer_datastructure_util_INFIXBINARYTREEITERATORSTRATEGY_HPP__

#include "IIteratorStrategy.hpp"
#include "../BinaryTreeNode.hpp"

namespace WarHammer
{
	namespace datastructure
	{
		namespace util
		{

			/**
			 * @class WarHammer::datastructure::util::InfixBinaryTreeIteratorStrategy
			 *
			 * @brief An implementation of WarHammer::datastructure::util::IIteratorStrategy based on In-fix Binary Tree walk.
			 *
			 * This class implements the algorithm of In-fix Binary Tree walk to the WarHammer::datastructure::Iterator.
			 *
			 * @tparam Content The content of the WarHammer::datastructure::BinaryTreeNode.
			 *
			 * @see WarHammer::datastructure::BinaryTreeNode
			 * @see WarHammer::datastructure::util::IIteratorStrategy
			 * @see WarHammer::datastructure::Iterator
			 *
			 * @author Felipe Wannmacher
			 */
			template<typename Content>
			class InfixBinaryTreeIteratorStrategy: public WarHammer::datastructure::util::IIteratorStrategy<WarHammer::datastructure::BinaryTreeNode<Content>, Content >
			{
			public:
				InfixBinaryTreeIteratorStrategy(void);
				virtual ~InfixBinaryTreeIteratorStrategy(void);
				/**
				 * @brief Verifies if the iterator can move to the next node.
				 *
				 * Verifies if the iterator can move to the next node based on the Binary Tree In-fix walk context.
				 *
				 * @param iterator The iterator that wants move to the next node.
				 *
				 * @return true if the iterator can move or false if cannot.
				 */
				bool hasNextNode(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator);
				/**
				 * @brief Verifies if the iterator can move to the previous node.
				 *
				 * Verifies if the iterator can move to the previous node based on the Binary Tree In-fix walk context.
				 *
				 * @param iterator The iterator that wants move to the previous node.
				 *
				 * @return true if the iterator can move or false if cannot.
				 */
				bool hasPreviousNode(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator);
				/**
				 * @brief Searches for the next node.
				 *
				 * Searches the next node for the iteration based on the Binary Tree In-fix walk context.
				 *
				 * @param iterator The iterator that will move to the next node.
				 *
				 * @return The next node of the iteration.
				 */
				WarHammer::datastructure::BinaryTreeNode<Content>* findNext(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator);
				/**
				 * @brief Searches for the previous node.
				 *
				 * Searches the previous node for the iteration based on the Binary Tree In-fix walk context.
				 *
				 * @param iterator The iterator that will move to the previous node.
				 *
				 * @return The previous node of the iteration.
				 */
				WarHammer::datastructure::BinaryTreeNode<Content>* findPrevious(WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content >* iterator);
				/**
				 * @brief Searches the first node of the iteration.
				 *
				 * Searches the first node for the iteration walking through the root of the tree based on the Binary Tree In-fix walk context.
				 *
				 * @param root The root node of the tree.
				 *
				 * @return The first node of the iteration.
				 */
				WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content > findFirst(WarHammer::datastructure::BinaryTreeNode<Content>* root);
				/**
				 * @brief Searches the last node of the iteration.
				 *
				 * Searches the last node for the iteration walking through the root of the tree based on the Binary Tree In-fix walk context.
				 *
				 * @param root The root node of the tree.
				 *
				 * @return The last node of the iteration.
				 */
				WarHammer::datastructure::Iterator<WarHammer::datastructure::BinaryTreeNode<Content>, Content > findLast(WarHammer::datastructure::BinaryTreeNode<Content>* root);
				/**
				 * @brief Get the node content.
				 *
				 * Get the content value of the received node.
				 *
				 * @param node The node that content will be given.
				 *
				 * @return The content value of the received node.
				 */
				Content getNodeContent(WarHammer::datastructure::BinaryTreeNode<Content>* node);
			};

		}
	}
}

#include "InfixBinaryTreeIteratorStrategy.tpp"

#endif
