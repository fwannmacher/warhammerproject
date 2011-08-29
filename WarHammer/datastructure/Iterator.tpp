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
 * Iterator.tpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_ITERATOR_HPP__

#include "exception/IteratorException.hpp"
#include "../exception/Exception.hpp"

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>::Iterator(void)
{
	this->_previous = NULL;
	this->_next = NULL;
	this->_current = NULL;
	this->_root = NULL;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>::Iterator(Node* root)
{
	this->_previous = NULL;
	this->_next = NULL;
	this->_current = NULL;
	this->_root = root;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>::Iterator(Node* previous, Node* next, Node* current)
{
	this->_previous = previous;
	this->_next = next;
	this->_current = current;
	this->_root = NULL;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>::~Iterator(void)
{
}

template<typename Node, typename Content>
bool WarHammer::datastructure::Iterator<Node, Content>::operator==(WarHammer::datastructure::Iterator<Node, Content> iterator)
{
	return (this->_current == iterator._current && this->_previous == iterator._previous && this->_next == iterator._next);
}

template<typename Node, typename Content>
bool WarHammer::datastructure::Iterator<Node, Content>::operator!=(WarHammer::datastructure::Iterator<Node, Content> iterator)
{
	return !((*this) == iterator);
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator=(WarHammer::datastructure::Iterator<Node, Content>& iterator)
{
	this->_previous = iterator._previous;
	this->_next = iterator._next;
	this->_current = iterator._current;
	this->_root = iterator._root;
	this->_strategy = iterator._strategy;

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator=(const WarHammer::datastructure::Iterator<Node, Content>& iterator)
{
	this->_previous = iterator._previous;
	this->_next = iterator._next;
	this->_current = iterator._current;
	this->_root = iterator._root;
	this->_strategy = iterator._strategy;

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator++(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	if(this->_current)
	{
		this->_previous = this->_current;
		this->_current = this->_next;

		if(this->_next)
			this->_next = this->_strategy->findNext(this);
	}

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content> WarHammer::datastructure::Iterator<Node, Content>::operator++(int increment)
{
	Iterator<Node, Content> iterator = (*this);

	try
	{
		++(*this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return iterator;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator--(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	if(this->_current)
	{
		this->_next = this->_current;
		this->_current = this->_previous;

		if(this->_previous)
			this->_previous = this->_strategy->findPrevious(this);
	}

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content> WarHammer::datastructure::Iterator<Node, Content>::operator--(int decrement)
{
	Iterator<Node, Content> iterator = (*this);

	try
	{
		--(*this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return iterator;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator+=(int increment)
{
	try
	{
		for(int i = 0; i < increment; ++i)
			++(*this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content>& WarHammer::datastructure::Iterator<Node, Content>::operator-=(int decrement)
{
	try
	{
		for(int i = 0; i < decrement; ++i)
			--(*this);
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return *this;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content> WarHammer::datastructure::Iterator<Node, Content>::operator+(int increment)
{
	Iterator<Node, Content> iterator = (*this);

	try
	{
		iterator += increment;
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return iterator;
}

template<typename Node, typename Content>
WarHammer::datastructure::Iterator<Node, Content> WarHammer::datastructure::Iterator<Node, Content>::operator-(int decrement)
{
	Iterator<Node, Content> iterator = (*this);

	try
	{
		iterator -= decrement;
	}
	catch(WarHammer::exception::Exception exception)
	{
		throw exception;
	}

	return iterator;
}

template<typename Node, typename Content>
Content WarHammer::datastructure::Iterator<Node, Content>::operator*(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	return this->_strategy->getNodeContent(this->_current);
}

template<typename Node, typename Content>
Content WarHammer::datastructure::Iterator<Node, Content>::operator->(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	return this->_strategy->getNodeContent(this->_current);
}

template<typename Node, typename Content>
bool WarHammer::datastructure::Iterator<Node, Content>::hasNext(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	return this->_strategy->hasNextNode(this);
}

template<typename Node, typename Content>
bool WarHammer::datastructure::Iterator<Node, Content>::hasPrevious(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	return this->_strategy->hasPreviousNode(this);
}

template<typename Node, typename Content>
Node* WarHammer::datastructure::Iterator<Node, Content>::getPreviousNode(void)
{
	return this->_previous;
}

template<typename Node, typename Content>
Node* WarHammer::datastructure::Iterator<Node, Content>::getNextNode(void)
{
	return this->_next;
}

template<typename Node, typename Content>
Node* WarHammer::datastructure::Iterator<Node, Content>::getCurrentNode(void)
{
	return this->_current;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::setPreviousNode(Node* previous)
{
	this->_previous = previous;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::setNextNode(Node* next)
{
	this->_next = next;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::setCurrentNode(Node* current)
{
	this->_current = current;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::setStrategy(WarHammer::util::SmartPointer<WarHammer::datastructure::util::IIteratorStrategy<Node, Content> > strategy)
{
	this->_strategy = strategy;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::goesFirst(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	if(!this->_root)
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_ROOT_NODE_POINTER, this);

	Iterator<Node, Content> first = this->_strategy->findFirst(this->_root);
	this->_previous = first._previous;
	this->_next = first._next;
	this->_current = first._current;
}

template<typename Node, typename Content>
void WarHammer::datastructure::Iterator<Node, Content>::goesLast(void)
{
	if(!this->_strategy.getContent())
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER, this);

	if(!this->_root)
		throw WarHammer::exception::Exception(WarHammer::datastructure::exception::IteratorException::NULL_ROOT_NODE_POINTER, this);

	Iterator<Node, Content> last = this->_strategy->findLast(this->_root);
	this->_previous = last._previous;
	this->_next = last._next;
	this->_current = last._current;
}

#endif
