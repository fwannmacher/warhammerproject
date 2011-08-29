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
 * SmartPointer.tpp
 *
 *  Created on: Oct 11, 2010
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_util_SMARTPOINTER_HPP__

#include "../exception/Exception.hpp"
#include "../exception/PointerException.hpp"

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(void)
{
	this->_content = NULL;
	this->_referenceCounter = NULL;
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(Content* content)
{
	this->_content = content;
	this->_addReference(NULL);
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(SmartPointer<Content>& pointer)
{
	this->_content = pointer._content;
	this->_addReference(pointer._referenceCounter);
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(const SmartPointer<Content>& pointer)
{
	SmartPointer<Content>& p = const_cast<SmartPointer<Content>&>(pointer);
	this->_content = p._content;
	this->_addReference(p._referenceCounter);
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(std::auto_ptr<Content>& pointer)
{
	this->_content = pointer.release();
	this->_addReference(NULL);
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::SmartPointer(const std::auto_ptr<Content>& pointer)
{
	this->_content = const_cast<std::auto_ptr<Content>&>(pointer).release();
	this->_addReference(NULL);
}

template<typename Content>
WarHammer::util::SmartPointer<Content>::~SmartPointer(void)
{
	this->_removeReference();
}

template<typename Content>
void WarHammer::util::SmartPointer<Content>::_addReference(unsigned int* referenceCounter)
{
	if(referenceCounter)
		this->_referenceCounter = referenceCounter;
	else
		this->_referenceCounter = new unsigned int(0);

	++(*this->_referenceCounter);
}

template<typename Content>
void WarHammer::util::SmartPointer<Content>::_removeReference(void)
{
	if(this->_referenceCounter)
		if(--(*this->_referenceCounter) == 0)
		{
			delete this->_content;
			delete this->_referenceCounter;
		}
}

template<typename Content>
WarHammer::util::SmartPointer<Content>& WarHammer::util::SmartPointer<Content>::operator=(Content* content)
{
	this->_removeReference();
	this->_content = content;
	this->_addReference(NULL);

	return *this;
}

template<typename Content>
WarHammer::util::SmartPointer<Content>& WarHammer::util::SmartPointer<Content>::operator=(SmartPointer<Content>& pointer)
{
	this->_removeReference();
	this->_content = pointer._content;
	this->_addReference(pointer._referenceCounter);

	return *this;
}

template<typename Content>
WarHammer::util::SmartPointer<Content>& WarHammer::util::SmartPointer<Content>::operator=(const SmartPointer<Content>& pointer)
{
	SmartPointer<Content>& p = const_cast<SmartPointer<Content>&>(pointer);
	this->_removeReference();
	this->_content = p._content;
	this->_addReference(p._referenceCounter);

	return *this;
}

template<typename Content>
WarHammer::util::SmartPointer<Content>& WarHammer::util::SmartPointer<Content>::operator=(std::auto_ptr<Content>& pointer)
{
	this->_removeReference();
	this->_content = pointer.release();
	this->_addReference(NULL);

	return *this;
}

template<typename Content>
WarHammer::util::SmartPointer<Content>& WarHammer::util::SmartPointer<Content>::operator=(const std::auto_ptr<Content>& pointer)
{
	this->_removeReference();
	this->_content = const_cast<std::auto_ptr<Content>&>(pointer).release();
	this->_addReference(NULL);

	return *this;
}

template<typename Content>
Content& WarHammer::util::SmartPointer<Content>::operator*(void)
{
	if(!this->_content)
		throw WarHammer::exception::Exception(WarHammer::exception::PointerException::NULL_POINTER, this);

	return *this->_content;
}

template<typename Content>
Content* WarHammer::util::SmartPointer<Content>::operator->(void)
{
	if(!this->_content)
		throw WarHammer::exception::Exception(WarHammer::exception::PointerException::NULL_POINTER, this);

	return this->_content;
}

template<typename Content>
Content* WarHammer::util::SmartPointer<Content>::releaseContent(void)
{
	Content* content = this->_content;
	this->_content = NULL;

	return content;
}

template<typename Content>
Content* WarHammer::util::SmartPointer<Content>::getContent(void)
{
	return this->_content;
}

#endif
