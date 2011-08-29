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
 * TextNode.cpp
 *
 *  Created on: Apr 19, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "TextNode.hpp"

WarHammer::markuplanguage::TextNode::TextNode(WarHammer::util::String content)
{
	this->_content = content;
}

WarHammer::markuplanguage::TextNode::~TextNode(void)
{
}

void WarHammer::markuplanguage::TextNode::addChild(WarHammer::markuplanguage::Component* child)
{
}

void WarHammer::markuplanguage::TextNode::addAttribute(WarHammer::markuplanguage::Attribute* attribute)
{
}

bool WarHammer::markuplanguage::TextNode::hasChildren(void)
{
	return false;
}

WarHammer::util::String WarHammer::markuplanguage::TextNode::getName(void)
{
	return "";
}

WarHammer::markuplanguage::Attribute* WarHammer::markuplanguage::TextNode::getAttribute(WarHammer::util::String attributeName)
{
	return NULL;
}

WarHammer::markuplanguage::Component* WarHammer::markuplanguage::TextNode::getChild(WarHammer::util::String childName)
{
	return NULL;
}

WarHammer::markuplanguage::Component* WarHammer::markuplanguage::TextNode::getFirstChild(void)
{
	return NULL;
}

std::vector<WarHammer::markuplanguage::Component*>& WarHammer::markuplanguage::TextNode::getChildren(void)
{
	std::vector<Component*>* children = NULL;
	return (*children);
}

std::vector<WarHammer::markuplanguage::Component*>& WarHammer::markuplanguage::TextNode::getChildren(WarHammer::util::String childrenName)
{
	std::vector<Component*>* children = NULL;
	return (*children);
}
