/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/08 11:27:36 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "../Iterator/ListIterator.hpp"

# include "../Node/Node.hpp"

// template <class T, class Alloc = std::allocator<T>>
template <typename T>
class List
{
	public: // typedef
		typedef T															value_type;
		// typedef Alloc														allocator_type;
		typedef T															&reference;
		typedef const T														&const_reference;
		typedef T															*pointer;
		typedef const T														*const_pointer;
		typedef Node<T> 													*node_pointer;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef ListIterator<value_type>									iterator;
		typedef ListIterator<value_type>									const_iterator;
		// typedef ReverseBI<iterator>											reverse_iterator;
		// typedef ReverseBI<const_iterator>									const_reverse_iterator;
	private:
		node_pointer	_head;
		node_pointer	_tail;
		// allocator_type	_alloc;
		size_type		_size;
	
	public:
		List() : _size(0)
		{
			this->_head = new Node<T>();
			this->_tail = this->_head;
		}
		List(size_type n, value_type val) : _size(0)
		{
			this->_head = new Node<T>(val);
			this->_tail = this->_head;
			this->insert(this->begin(), n - 1, val);
		}
		void insert(iterator position, value_type val)
		{
			node_pointer node = new Node<T>(position.ptr->getPrev(), position.ptr, val);
			
			if (node->getPrev())
				node->prev->next = node;
			else
				this->_head = node;
			node->next->prev = node;
			this->_size++;
			// if (!node->next)
			// 	this->_tail = node;
			// return iterator(node);
		}
		void insert(iterator position, size_type n, value_type val)
		{
			while (n > 0)
			{
				insert(position, val);
				--n;
			}
		}
		iterator begin()
		{
			return iterator(this->_head);
		}
		iterator end()
		{
			return iterator(this->_tail);
		}

		void print()
		{
			std::cout << "head = " << *(this->begin()) << " | tail = " << *(this->end()) << "\n\n";
			ListIterator<value_type> it = this->begin();
			for (int i = 0; i < 10; i++)
			{
				std::cout << *it << "\n";
				it++;
			}
		}
};

#endif // LIST_HPP