/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/05 17:40:07 by bdekonin      ########   odam.nl         */
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

	public:
		_node *getNode() {return this->_n;}
		bool operator==(const ListIterator<T>& rhs) const
		{
			return (this->_n == rhs._n);
			// return false;
		}
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
		_node		*_head; // last
		_node		*_tail; // last _node
		size_type	_size; // size
	
	public:
		/* Constructor  */
		List()
		{
			this->_head = new _node(nullptr, nullptr);
			this->_tail = this->_head;
		}

		List(size_type n, value_type val)
		: _head(nullptr), _tail(nullptr)
		{
			this->_head = new _node(nullptr, nullptr, val);
			this->insert(this->begin(), n - 1, val);
		}

		void insert(iterator position, value_type val)
		{
			_node *insertion = new _node(nullptr, nullptr, val);
			_node *one = position._n;

			if (this->_head == nullptr)
			{
				this->_head = insertion;
				return;
			}
			if (one == nullptr)
				this->ft_lstadd_back(&this->_head, insertion);
			else
				ft_node_insert_before(&this->_head, insertion, one);
		}
		
		/* Methods */
		void insert(iterator position, size_type n, value_type val)
		{
			while (n > 0)
			{
				this->insert(position, val);
				n--;
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
		void	ft_node_add_front(_node **head, _node *neww)
		{
			neww->next = *head;
			if (*head)
				(*head)->prev = neww;
			*head = neww;
		}
		void	ft_node_insert_before(_node **head, _node *node, _node *before_this)
		{
			if (before_this == *head)
			{
				ft_node_add_front(head, node);
				return ;
			}
			node->prev = before_this->prev;
			node->next = before_this;
			before_this->prev = node;
			node->prev->next = node;	
		}
		template <typename _T>
		friend class ListIterator; // So ListIterator can access private rights
};

#endif // LIST_HPP