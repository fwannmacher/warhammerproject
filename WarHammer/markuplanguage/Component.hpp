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
 * Component.hpp
 *
 *  Created on: Apr 19, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_markuplanguage_COMPONENT_HPP__
#define __WarHammer_markuplanguage_COMPONENT_HPP__

#include "Attribute.hpp"
#include "../datastructure/TreeNode.hpp"
#include "../util/String.hpp"

namespace WarHammer
{
	namespace markuplanguage
	{

		/**
		 * @class WarHammer::markuplanguage::Component
		 *
		 * @brief An abstract extension of the WarHammer::datastructure::TreeNode that has markup language specific methods.
		 *
		 * WarHammer::markuplanguage::Component is an abstract class that encapsulates some methods for usage of markup languages node. This class extends the WarHammer::datastructure::TreeNode using the content of the node as WarHammer::util::String.
		 *
		 * @see WarHammer::datastructure::TreeNode
		 *
		 * @author Felipe Wannmacher
		 */
		class Component: public WarHammer::datastructure::TreeNode<WarHammer::util::String, Component>
		{
		public:
			Component(void);
			virtual ~Component(void);
			/**
			 * @brief Adds an attribute in the node.
			 *
			 * Adds an attribute to the attributes list of the node.
			 *
			 * @param attribute An instance of WarHammer::markuplanguage::Attribute.
			 *
			 * @see WarHammer::markuplanguage::Attribute
			 */
			virtual void addAttribute(Attribute* attribute) = 0;
			/**
			 * @brief Get the node's name.
			 *
			 * Get the tag name of the markup language node.
			 *
			 * @return The node's name
			 */
			virtual WarHammer::util::String getName(void) = 0;
			/**
			 * @brief Get the node's attribute that has the parameter name.
			 *
			 * Get a pointer of an attribute that has the name equals the passed parameter.
			 *
			 * @param attributeName The attribute's name.
			 *
			 * @return A pointer of an attribute.
			 */
			virtual Attribute* getAttribute(WarHammer::util::String attributeName) = 0;
			/**
			 * @brief Get the node's child that has the parameter name.
			 *
			 * Get a pointer of the first markup language node child that has the tag name equals the passed parameter.
			 *
			 * @param childName The child node's name.
			 *
			 * @return A pointer of a node.
			 */
			virtual Component* getChild(WarHammer::util::String childName) = 0;
			/**
			 * @brief Get all child nodes with the parameter name.
			 *
			 * Get a vector of child nodes those have the tag name equals the passed parameter.
			 *
			 * @param childrenName The child node's name.
			 *
			 * @return A vector of nodes.
			 */
			virtual std::vector<Component*>& getChildren(WarHammer::util::String childrenName) = 0;
			/**
			 * @brief Get all child nodes of the current node.
			 *
			 * Get a vector with all child nodes of the current node.
			 *
			 * @return A vector of nodes.
			 */
			virtual std::vector<Component*>& getChildren(void);
		};

	}
}

#endif
