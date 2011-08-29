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
 * Loader.cpp
 *
 *  Created on: Apr 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#include "Loader.hpp"

const char WarHammer::markuplanguage::Loader::__ASCII_SPACE = 32;
const char WarHammer::markuplanguage::Loader::__ASCII_TABULATION = 9;
const char WarHammer::markuplanguage::Loader::__ASCII_RETURN = 10;

WarHammer::markuplanguage::Loader::Loader(WarHammer::markuplanguage::IBuilder* builder)
{
	this->_builder = builder;
}

WarHammer::markuplanguage::Loader::~Loader(void)
{
	delete this->_builder;
}

void WarHammer::markuplanguage::Loader::_closeNode(void)
{
	while(this->_fileContent[++this->_currentFileContentIndex] != '>');

	this->_builder->buildCloseNode();
}

WarHammer::util::String WarHammer::markuplanguage::Loader::_loadNode(void)
{
	unsigned int tokenEndIndex = this->_fileContent.indexOf('>', ++this->_currentFileContentIndex),
				 tokenSpaceIndex = this->_fileContent.indexOf(' ', this->_currentFileContentIndex),
				 tokenLength = tokenEndIndex - this->_currentFileContentIndex;

	if(tokenEndIndex < tokenSpaceIndex)
		tokenLength = tokenEndIndex;
	else
		tokenLength = tokenSpaceIndex;

	tokenLength -= this->_currentFileContentIndex;

	WarHammer::util::String nodeName = this->_fileContent.substring(this->_currentFileContentIndex, tokenLength);
	this->_currentFileContentIndex += tokenLength;

	this->_builder->buildNode(nodeName);

	return nodeName;
}

void WarHammer::markuplanguage::Loader::_loadTextNode(WarHammer::util::String parentNodeName)
{
	bool done = false;
	unsigned int tokenLength = this->_fileContent.indexOf("</" + parentNodeName + ">", this->_currentFileContentIndex) - this->_currentFileContentIndex,
				 tokenBeginIndex = this->_currentFileContentIndex;
	this->_currentFileContentIndex += tokenLength;

	while(!done)
		switch(this->_fileContent[tokenBeginIndex + tokenLength - 1])
		{
		case Loader::__ASCII_SPACE:
		case Loader::__ASCII_TABULATION:
		case Loader::__ASCII_RETURN:
			--tokenLength;
			break;
		default:
			done = true;
			break;
		}

	this->_builder->buildTextNode(this->_fileContent.substring(tokenBeginIndex, tokenLength));
}

void WarHammer::markuplanguage::Loader::_loadAttribute(void)
{
	unsigned int separatorIndex = this->_fileContent.indexOf('=', this->_currentFileContentIndex);
	WarHammer::util::String attributeName = this->_fileContent.substring(this->_currentFileContentIndex, separatorIndex - this->_currentFileContentIndex),
				attributeValue = this->_fileContent.substring(separatorIndex + 2, this->_fileContent.indexOf('"', separatorIndex + 2) - (separatorIndex + 2));

	this->_builder->buildAttribute(attributeName, attributeValue);

	this->_currentFileContentIndex += attributeName.length() + attributeValue.length() + 2;
}

void WarHammer::markuplanguage::Loader::_loadSpecificNode(void)
{
	unsigned int tokenLength = this->_fileContent.indexOf('>', this->_currentFileContentIndex) - this->_currentFileContentIndex;

	this->_builder->buildSpecificNode(this->_fileContent.substring(this->_currentFileContentIndex, tokenLength));

	this->_currentFileContentIndex += tokenLength;
}

void WarHammer::markuplanguage::Loader::_loadSpecialNode(void)
{
	this->_currentFileContentIndex += 2;

	if(this->_fileContent.substring(this->_currentFileContentIndex, 7) == "[CDATA[")
		this->_loadCDATA();
	else if(this->_fileContent.substring(this->_currentFileContentIndex, 7) == "DOCTYPE")
		this->_loadDOCTYPE();
}

void WarHammer::markuplanguage::Loader::_loadCDATA(void)
{
	bool done = false;

	this->_currentFileContentIndex += 7;

	if(this->_fileContent[this->_currentFileContentIndex] == Loader::__ASCII_RETURN)
		++this->_currentFileContentIndex;

	unsigned int tokenLength = this->_fileContent.indexOf("]]>", this->_currentFileContentIndex) - this->_currentFileContentIndex,
				 tokenBeginIndex = this->_currentFileContentIndex;
	this->_currentFileContentIndex += tokenLength + 2;

	while(!done)
		switch(this->_fileContent[tokenBeginIndex + tokenLength - 1])
		{
		case Loader::__ASCII_SPACE:
		case Loader::__ASCII_TABULATION:
		case Loader::__ASCII_RETURN:
			--tokenLength;
			break;
		default:
			done = true;
			break;
		}

	this->_builder->buildTextNode(this->_fileContent.substring(tokenBeginIndex, tokenLength));
}

void WarHammer::markuplanguage::Loader::_loadDOCTYPE(void)
{
	//TODO do the DOCTYPE implementation
	this->_currentFileContentIndex = this->_fileContent.indexOf('>', this->_currentFileContentIndex);
}

void WarHammer::markuplanguage::Loader::_passComment(void)
{
	this->_currentFileContentIndex = this->_fileContent.indexOf("-->", this->_currentFileContentIndex) + 2;
}

WarHammer::util::SmartPointer<WarHammer::markuplanguage::Container> WarHammer::markuplanguage::Loader::load(WarHammer::io::File& xmlFile)
{
	return this->load(xmlFile.readAll());
}

WarHammer::util::SmartPointer<WarHammer::markuplanguage::Container> WarHammer::markuplanguage::Loader::load(WarHammer::util::String xml)
{
	char character = 0,
		 lastValidCharacter = 0;
	WarHammer::util::String lastLoadedNode = "";

	this->_fileContent = xml;

	for(this->_currentFileContentIndex = 0; this->_currentFileContentIndex < this->_fileContent.length(); ++this->_currentFileContentIndex)
	{
		switch(this->_fileContent[this->_currentFileContentIndex])
		{
		case Loader::__ASCII_SPACE:
		case Loader::__ASCII_TABULATION:
		case Loader::__ASCII_RETURN:
		case '>':
			break;
		case '<':
			character = this->_fileContent[this->_currentFileContentIndex + 1];

			if((character > 64 && character < 91) || (character > 96 && character < 123))
				lastLoadedNode = this->_loadNode();
			else if(character == '/')
				this->_closeNode();
			else if(character == '!')
			{
				if(this->_fileContent[this->_currentFileContentIndex + 2] == '-')
					this->_passComment();
				else
					this->_loadSpecialNode();
			}
			else
				this->_loadSpecificNode();

			lastValidCharacter = this->_fileContent[this->_currentFileContentIndex];
			break;
		case '/':
			this->_closeNode();
			break;
		default:
			if(lastValidCharacter == '>')
				this->_loadTextNode(lastLoadedNode);
			else
				this->_loadAttribute();

			break;
		}
	}

	return this->_builder->getResult();
}
