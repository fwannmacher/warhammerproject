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
 * Iterator.hpp
 *
 *  Created on: May 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifndef __WarHammer_datastructure_ITERATOR_HPP__
#define __WarHammer_datastructure_ITERATOR_HPP__

#include "util/IIteratorStrategy.hpp"
#include "../util/SmartPointer.hpp"

namespace WarHammer
{
	namespace datastructure
	{
		namespace util
		{

			template<typename Node, typename Content>
			class IIteratorStrategy;

		}

		/**
		 * @class WarHammer::datastructure::Iterator
		 *
		 * @brief An iterator class based on Strategy Pattern.
		 *
		 * WarHammer::datastructure::Iterator is a generic class that uses the Design Pattern Strategy for implementation of the iteration rules.
		 *
		 * @tparam Node The node type that the iterator will iterate.
		 * @tparam Content The content of the node type.
		 *
		 * @see WarHammer::datastructure::util::IIteratorStrategy
		 *
		 * @author Felipe Wannmacher
		 */
		template<typename Node, typename Content>
		class Iterator
		{
		private:
			Node* _previous,
				* _next,
				* _current,
				* _root;
			WarHammer::util::SmartPointer<WarHammer::datastructure::util::IIteratorStrategy<Node, Content> > _strategy;
		public:
			/**
			 * @brief Compares the current iterator with another iterator.
			 *
			 * Compares if the current iterator has the same current, next and previous nodes than the another iterator.
			 *
			 * @param iterator Another iterator to be compared with the current iterator.
			 *
			 * @return true if the current iterator has the same current, next and previous nodes than the another iterator or false if it hasn't.
			 */
			bool operator==(Iterator iterator);
			/**
			 * @brief Compares the current iterator with another iterator.
			 *
			 * Compares if the current iterator has a different value in current, next or previous nodes than the another iterator.
			 *
			 * @param iterator Another iterator to be compared with the current iterator.
			 *
			 * @return true if the current iterator has a different value in current, next or previous nodes than the another iterator or false if it hasn't.
			 */
			bool operator!=(Iterator iterator);
			/**
			 * @brief Copies another iterator.
			 *
			 * Copies the attributes of another iterator including the strategy and the root node.
			 *
			 * @param iterator Another iterator to be copied.
			 *
			 * @return The iterator itself with the new values.
			 */
			Iterator& operator=(Iterator& iterator);
			/**
			 * @brief Copies another iterator.
			 *
			 * Copies the attributes of another iterator including the strategy and the root node.
			 *
			 * @param iterator Another iterator to be copied.
			 *
			 * @return The iterator itself with the new values.
			 */
			Iterator& operator=(const Iterator& iterator);
			/**
			 * @brief Increments the iterator position.
			 *
			 * Increments the iterator position to the next node based on the strategy set.
			 *
			 * @return The iterator itself positioned on the next node.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			Iterator& operator++(void);
			/**
			 * @brief Creates a new iterator with the next position of the current iterator.
			 *
			 * Creates a new iterator positioned on the next node of the current iterator based on the strategy set. That iterator copies the current iterator.
			 *
			 * @return A new iterator positioned on the next node of the current iterator.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator++()
			 */
			Iterator operator++(int increment);
			/**
			 * @brief Decrements the iterator position.
			 *
			 * Decrements the iterator position to the previous node based on the strategy set.
			 *
			 * @return The iterator itself positioned on the previous node.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			Iterator& operator--(void);
			/**
			 * @brief Creates a new iterator with the previous position of the current iterator.
			 *
			 * Creates a new iterator positioned on the previous node of the current iterator based on the strategy set. That iterator copies the current iterator.
			 *
			 * @return A new iterator positioned on the previous node of the current iterator.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator--()
			 */
			Iterator operator--(int decrement);
			/**
			 * @brief Increments the iterator position some times.
			 *
			 * Increments the iterator position to the next node base on the strategy set some times.
			 *
			 * @param increment The quantity of times the iterator position will be incremented.
			 *
			 * @return The iterator itself positioned on the new position.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator++()
			 */
			Iterator& operator+=(int increment);
			/**
			 * @brief Decrements the iterator position some times.
			 *
			 * Decrements the iterator position to the previous node base on the strategy set some times.
			 *
			 * @param decrement The quantity of times the iterator position will be decremented.
			 *
			 * @return The iterator itself positioned on the new position.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator--()
			 */
			Iterator& operator-=(int decrement);
			/**
			 * @brief Creates a new iterator with the current iterator position incremented some times.
			 *
			 * Creates a new iterator positioned on the next node of the current iterator based on the strategy set incremented some times. That iterator copies the current iterator.
			 *
			 * @param increment The quantity of times the iterator position will be incremented.
			 *
			 * @return A new iterator positioned on the new position.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator+=()
			 */
			Iterator operator+(int increment);
			/**
			 * @brief Creates a new iterator with the current iterator position decremented some times.
			 *
			 * Creates a new iterator positioned on the previous node of the current iterator based on the strategy set decremented some times. That iterator copies the current iterator.
			 *
			 * @param decrement The quantity of times the iterator position will be decremented.
			 *
			 * @return A new iterator positioned on the new position.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 *
			 * @see WarHammer::datastructure::Iterator::operator-=()
			 */
			Iterator operator-(int decrement);
			/**
			 * @brief Access the content of the current node.
			 *
			 * Access the content of the current node based on the strategy set.
			 *
			 * @return The content of the current node.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			Content operator*(void);
			/**
			 * @brief Access the content of the current node.
			 *
			 * Access the content of the current node based on the strategy set.
			 *
			 * @return The content of the current node.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			Content operator->(void);
		public:
			Iterator(void);
			/**
			 * @brief Custom constructor.
			 *
			 * A custom constructor that set the root node of the iterator.
			 *
			 * @param root The root node of the container.
			 */
			Iterator(Node* root);
			/**
			 * @brief Custom constructor.
			 *
			 * A custom constructor that set the previous node, the next node and the current node.
			 *
			 * @param previous The previous node.
			 * @param next The next node.
			 * @param current The current node.
			 */
			Iterator(Node* previous, Node* next, Node* current);
			virtual ~Iterator(void);
			/**
			 * @brief Verifies if iterator has a next node to move.
			 *
			 * The iterator call the current strategy to verifies if it has a next node that can move to it.
			 *
			 * @return true if can move to the next node or false if cannot.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			bool hasNext(void);
			/**
			 * @brief Verifies if iterator has a previous node to move.
			 *
			 * The iterator call the current strategy to verifies if it has a previous node that can move to it.
			 *
			 * @return true if can move to the previous node or false if cannot.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 */
			bool hasPrevious(void);
			/**
			 * @brief Get the previous node.
			 *
			 * Get the previous node of the iteration.
			 *
			 * @return The previous node of the iteration.
			 */
			Node* getPreviousNode(void);
			/**
			 * @brief Get the next node.
			 *
			 * Get the next node of the iteration.
			 *
			 * @return The next node of the iteration.
			 */
			Node* getNextNode(void);
			/**
			 * @brief Get the current node.
			 *
			 * Get the current node of the iteration.
			 *
			 * @return The current node of the iteration.
			 */
			Node* getCurrentNode(void);
			/**
			 * @brief Set the previous node.
			 *
			 * Set the previous node of the iteration.
			 *
			 * @param previous The previous node of the iteration.
			 */
			void setPreviousNode(Node* previous);
			/**
			 * @brief Set the next node.
			 *
			 * Set the next node of the iteration.
			 *
			 * @param next The next node of the iteration.
			 */
			void setNextNode(Node* next);
			/**
			 * @brief Set the current node.
			 *
			 * Set the current node of the iteration.
			 *
			 * @param current The current node of the iteration.
			 */
			void setCurrentNode(Node* current);
			/**
			 * @brief Set the strategy.
			 *
			 * Set the iteration strategy.
			 *
			 * @param strategy A pointer of an implementation of the WarHammer::datastructure::util::IIteratorStrategy.
			 *
			 * @see WarHammer::datastructure::util::IIteratorStrategy
			 */
			void setStrategy(WarHammer::util::SmartPointer<WarHammer::datastructure::util::IIteratorStrategy<Node, Content> > strategy);
			/**
			 * @brief Goes to the first node.
			 *
			 * Moves the iterator to the first node based on the strategy set.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_ROOT_NODE_POINTER if root node is not set.
			 */
			void goesFirst(void);
			/**
			 * @brief Goes to the last node.
			 *
			 * Moves the iterator to the last node based on the strategy set.
			 *
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_STRATEGY_POINTER if strategy is not set.
			 * @exception WarHammer::datastructure::exception::IteratorException::NULL_ROOT_NODE_POINTER if root node is not set.
			 */
			void goesLast(void);
		};

	}
}

#include "Iterator.tpp"

#endif
