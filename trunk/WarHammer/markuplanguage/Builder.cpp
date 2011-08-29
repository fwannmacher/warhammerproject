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
 * Builder.cpp
 *
 *  Created on: Apr 24, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Builder.hpp"

WarHammer::markuplanguage::Builder::~Builder(void)
{
}

WarHammer::util::SmartPointer<WarHammer::markuplanguage::Container> WarHammer::markuplanguage::Builder::getResult(void)
{
	this->_container->setRootNode(this->_rootNode);

	return WarHammer::util::SmartPointer<Container>(this->_container);
}

void WarHammer::markuplanguage::Builder::buildNode(WarHammer::util::String nodeName)
{
	Component* node = new Node(nodeName);

	if(!this->_openNodes.empty())
		this->_openNodes.top()->addChild(node);
	else
		this->_rootNode = node;

	this->_openNodes.push(node);
}

void WarHammer::markuplanguage::Builder::buildCloseNode(void)
{
	this->_openNodes.pop();
}

void WarHammer::markuplanguage::Builder::buildTextNode(WarHammer::util::String nodeValue)
{
	this->_openNodes.top()->addChild(new TextNode(nodeValue));
}

void WarHammer::markuplanguage::Builder::buildAttribute(WarHammer::util::String attributeName, WarHammer::util::String attributeValue)
{
	static_cast<Node*>(this->_openNodes.top())->addAttribute(new Attribute(attributeName, attributeValue));
}
