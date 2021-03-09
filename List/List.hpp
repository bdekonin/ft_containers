/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/09 15:59:59 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "../Iterator/ListIterator.hpp"
# include "../Node/Node.hpp"

// https://www.cplusplus.com/reference/list/list/

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
	/* Member functions */
		List()
		: _size(0)
		{
			this->_head = new Node<T>();
			this->_tail = new Node<T>();

			this->_setHeadAndTail();
		}
		List(size_type n, value_type val)
		: _size(1)
		{
			if (n == 0)
			{
				this->_head = new Node<T>();
				this->_tail = new Node<T>();
				this->_size = 0;
				this->_setHeadAndTail();
				return ;
			}
			this->_head = new Node<T>(val);
			this->_tail = new Node<T>(NULL);

			this->_setHeadAndTail();
			this->insert(this->begin(), n - 1, val);
		}
	/* M̶e̶m̶b̶e̶r̶ ̶f̶u̶n̶c̶t̶i̶o̶n̶s̶ */
		
	/* Iterators */
		iterator begin()
		{
			return iterator(this->_head);
		}
		iterator end()
		{
			return iterator(this->_tail);
		}
		/* rbegin */
		/* rend */
		const_iterator cbegin()
		{
			return const_iterator(this->_head);
		}
		const_iterator cend()
		{
			return const_iterator(this->_tail);
		}
		/* crbegin */
		/* crend */
	/* I̶t̶e̶r̶a̶t̶o̶r̶s̶ */
		

	/* Capacity */
		bool empty()
		{
			return (this->_tail->content == 0);
		}
		size_type size()
		{
			return this->_size;
		}
		/* max_size */
	/* C̶a̶p̶a̶c̶i̶t̶y̶ */


	/* Element access */
		reference front()
		{
			return *this->begin();
		}
		const_reference front() const
		{
			return *this->begin();
		}
		reference back()
		{
			return *(this->end()--);
		}
		const_reference back() const
		{
			return *(this->end()--);
		}
	/* E̶l̶e̶m̶e̶n̶t̶ ̶a̶c̶c̶e̶s̶s̶ */
		
		
	/* Modifiers */
		/* assign */
		iterator insert(iterator position, value_type &val)
		{
			node_pointer node = new Node<T>(nullptr, nullptr, val);

			this->ft_node_insert_before(&this->_head, node, position.ptr);
			this->_tail->next = this->_head;
			this->_head->prev = this->_tail;
			
			this->_size++;
			return iterator(node);
		}
		void insert(iterator position, size_type n, value_type &val)
		{
			while (n > 0)
			{
				this->insert(position, val);
				--n;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				std::cout << "kees " << *first << "\n";
				this->insert(position, *first);
				first++;
			}
		}
	/* M̶o̶d̶i̶f̶i̶e̶r̶s̶ */


	/* Operations */

	/* O̶p̶e̶r̶a̶t̶i̶o̶n̶s̶ */
		
	private:
		void	_setHeadAndTail() //  sets the head and tail correctly
		{
			this->_head->prev = this->_tail;
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_tail->next = this->_head;
		}
		void	ft_node_insert_before(Node<T> **head, Node<T> *node, Node<T> *before_this)
		{
			if (before_this == *head)
			{
				node->next = *head;
				if (*head)
					(*head)->prev = node;
				*head = node;
				return ;
			}
			node->prev = before_this->prev;
			node->next = before_this;
			before_this->prev = node;
			node->prev->next = node;
		}
	public:
		void print()
		{
			this->print((int)this->size() + 1);
		}
		void print(int size)
		{
			std::cout << "head = " << this->_head << " | tail = " << this->_tail << "\n\n";
			ListIterator<value_type> it = this->begin();
			for (int i = 0; i < size; i++)
			{
				std::cout << "(" << i + 1 << ")\t- " << "[" << *it << "]";
				if (it == this->_head)
					std::cout << " --> HEAD";
				else if (it == this->_tail)
					std::cout << " --> TAIL";
				std::cout << "\n";
				it++;
			}
		}
};

#endif // LIST_HPP
