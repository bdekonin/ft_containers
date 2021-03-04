/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/04 19:03:19 by bdekonin      ########   odam.nl         */
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
		typedef T &reference;
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

		/* Methods */
		_node *getHead(_node *node)
		{
			while (node->prev)
			{
				node = node->prev;
				std::cout << "i";
			}
			std::cout << "\n";
			return (node);
		}
	public:

		ListIterator<T>  operator=(const ListIterator<T>  &o)
		{
			this->_n = o._n;
			return *this;
		}
		ListIterator<T>  operator++(int)
		{
			if (this->_n->next == nullptr)
				this->_n = this->getHead(this->_n);
			else
				this->_n = this->_n->next;
			return *this;
		}
		ListIterator<T>  operator--(int)
		{
			this->_n = this->_n->prev;
			return *this;
		}
		reference operator*() const
		{
			return this->_n->content;
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
			if (n > 1)
				this->insert(this->begin(), n - 1, val);
		}
		
		/* Methods */
		void insert(iterator position, size_type n, value_type val)
		{
			_node *newHead = new _node(nullptr, nullptr, val);
			_node *lastNewHead;
			for (size_type i = 1; i < n; i++)
				this->ft_lstadd_back(&newHead, new _node(nullptr, nullptr, val));
			lastNewHead = this->ft_lstlast(newHead);
			
			if (position._n->prev == nullptr)
			{
				position._n->prev = lastNewHead;
				lastNewHead->next = position._n;
				this->_head = newHead;
			}
			else if (position._n == this->ft_lstlast(this->_head))
			{
				this->ft_lstadd_back(&this->_head, newHead);
			}
			else
			{
				_node *left = position._n->prev;
				
				left->next = newHead;
				newHead->prev = left;
				
				position._n->prev = lastNewHead;
				lastNewHead->next = position._n;
			}
		}

		void print()
		{
			for (_node *test = this->_head; test; test = test->next)
				std::cout << test->content << std::endl;
		}
		iterator begin()
		{
			return iterator(this->_head);
		}
	private:
		void ft_lstadd_back(_node **head, _node *neww)
		{
			_node *last;

			if (!neww)
				return ;
			if (*head)
			{
				last = ft_lstlast(*head);
				last->next = neww;
				neww->prev = last;
			}
		}
		_node *ft_lstlast(_node *lst)
		{
			if (!lst)
				return nullptr;
			while (lst->next != NULL)
				lst = lst->next;
			this->_tail = lst;
			return (lst);
		}
		
		template <typename _T>
		friend class ListIterator; // So ListIterator can access private rights
};

#endif // LIST_HPP