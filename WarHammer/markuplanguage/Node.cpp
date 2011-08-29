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
 * Node.cpp
 *
 *  Created on: Apr 19, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Node.hpp"

WarHammer::markuplanguage::Node::Node(WarHammer::util::String name): WarHammer::markuplanguage::Component()
{
	this->_name = name;
}

WarHammer::markuplanguage::Node::~Node(void)
{
	for(unsigned int i = 0; i < this->_children.size(); ++i)
		delete this->_children[i];

	for(std::map<std::string, Attribute*>::iterator iterator = this->_attributes.begin(); iterator != this->_attributes.end(); ++iterator)
		delete iterator->second;

	this->_children.clear();
	this->_childrenHash.clear();
	this->_attributes.clear();
}

void WarHammer::markuplanguage::Node::addChild(Component* child)
{
	Component::addChild(child);

	if(!child->getName().isEmpty())
		this->_childrenHash[child->getName().getContent()].push_back(child);
}

void WarHammer::markuplanguage::Node::addAttribute(WarHammer::markuplanguage::Attribute* attribute)
{
	this->_attributes[attribute->getName().getContent()] = attribute;
}

WarHammer::util::String WarHammer::markuplanguage::Node::getContent(void)
{
	return "";
}

WarHammer::util::String WarHammer::markuplanguage::Node::getName(void)
{
	return this->_name;
}

WarHammer::markuplanguage::Attribute* WarHammer::markuplanguage::Node::getAttribute(WarHammer::util::String attributeName)
{
	return this->_attributes[attributeName.getContent()];
}

WarHammer::markuplanguage::Component* WarHammer::markuplanguage::Node::getChild(WarHammer::util::String childName)
{
	return this->_children.empty() ? NULL : this->_childrenHash[childName.getCString()][0];
}

std::vector<WarHammer::markuplanguage::Component*>& WarHammer::markuplanguage::Node::getChildren(WarHammer::util::String childrenName)
{
	return this->_childrenHash[childrenName.getContent()];
}

void WarHammer::markuplanguage::Node::setContent(WarHammer::util::String content)
{
}
