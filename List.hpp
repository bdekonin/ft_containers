/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/01 21:57:15 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>



template <typename T>
class List;

template <typename T>
class ListIterator
{
	public:
		// test
		ListIterator()
		{
		}
		void print()
		{
			std::cout << "node = " << _n->content << std::endl;
		}
	private:
		typedef typename List<T>::_node _node;		
		_node *_n;
		
		ListIterator(_node *node) : _n(node) // only accessed by friend classes
		{
		}
	public:

		ListIterator<T>  operator=(const ListIterator<T>  &o)
		{
			this->_n = o._n;
			return *this;
		}
		ListIterator<T>  operator++(int)
		{
			this->_n = this->_n->next;
			return *this;
		}
		ListIterator<T>  operator--(int)
		{
			this->_n = this->_n->prev;
			return *this;
		}


		// So List can call a private constructor
		template <typename _T>
		friend class List;
		template <typename _T>
		friend class ListIterator;
};


template <typename T>
class List
{
	public: // typedef
		typedef size_t size_type;
		typedef ListIterator<T> iterator;
		typedef T value_type;
	private:
		/*
		**	Double Linked List
		*/
		struct _node
		{
			struct _node	*next;
			struct _node	*prev;
			
			T				content;

			_node(_node *_prev, _node *_next)
				: prev(_prev), next(_next)
			{}
			_node(_node *_prev, _node *_next, T _content)
				: prev(_prev), next(_next), content(_content)
			{}
		};
		
		_node	*_head; // last
		_node	*_tail; // last _node
	
	public:
		/* Constructor  */
		List()
		{
			this->_head = new _node(nullptr, nullptr);
			this->_tail = this->_head;
		}

		List(size_type n, value_type val)
		{
			this->_head = new _node(nullptr, nullptr, val);
			this->_tail = this->_head;
			this->insert(this->begin(), n, val);
		}

		/* Methods */
		void insert(iterator position, size_type n, value_type val)
		{
			_node *alst = new _node(nullptr, nullptr, val);
			_node *last = alst;
			_node *newNode;
			for (size_type i = 0; i < (n - 1); i++)
			{
				newNode = new _node(nullptr, nullptr, val);
				last->next = newNode;
				newNode->prev = last;
			}
			_node *positionNode = position._n;
			if (positionNode->prev)
			{
				positionNode->prev->next = 
			}
		}


				/* Methods */
				void insert()
				{
					this->_head->next = new _node(this->_head, nullptr, 1);
					this->_head->next->next = new _node(this->_head->next, nullptr, 2);
					this->_head->next->next->next = new _node(this->_head->next->next, nullptr, 3);
					this->_head->next->next->next->next = new _node(this->_head->next->next->next, nullptr, 4);
				}
		iterator begin()
		{
			return iterator(this->_head);
		}
	private:
		template <typename _T>
		friend class ListIterator; // So ListIterator can access private rights
};

#endif // LIST_HPP