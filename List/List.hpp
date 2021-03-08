/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/08 19:42:04 by bdekonin      ########   odam.nl         */
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
	
	public:
		List()
		{
			this->_head = new Node<T>();
			this->_tail = new Node<int>(1);

			this->_head->prev = this->_tail;
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_tail->next = this->_head;
		}
		List(size_type n, value_type val)
		{
			this->_head = new Node<T>(val);
			this->_tail = new Node<int>(1);

			this->_head->prev = this->_tail;
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_tail->next = this->_head;
			
			this->insert(this->begin(), n - 1, val);
		}

		iterator insert(iterator position, value_type val)
		{
			node_pointer node = new Node<T>(nullptr, nullptr, val);

			this->ft_node_insert_before(&this->_head, node, position.ptr);
			this->_tail->next = this->_head;
			this->_head->prev = this->_tail;
			this->_tail->content++;
			return iterator(node);
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
		size_type size()
		{
			return (size_type)this->end().ptr->content;
		}
	private:
		void	ft_node_insert_after(Node<T> *node, Node<T> *after_this)
		{
			node->prev = after_this;
			node->next = after_this->next;
			after_this->next = node;
			if (node->next)
				node->next->prev = node;
		}
		void	ft_node_insert_before(Node<T> **head, Node<T> *node, Node<T> *before_this)
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
		void	ft_node_add_front(Node<T> **head, Node<T> *neww)
		{
			neww->next = *head;
			if (*head)
				(*head)->prev = neww;
			*head = neww;
		}
		void	ft_node_add_back(Node<T> **head, Node<T> *neww)
		{
			Node<T>	*tmp;

			if (!*head)
				ft_node_add_front(head, neww);
			else
			{
				tmp = ft_node_last(*head);
				tmp->next = neww;
				neww->prev = tmp;
			}
		}
		Node<T>	*ft_node_last(Node<T> *node)
		{
			Node<T>	*tmp;

			if (!node)
				return (NULL);
			tmp = node;
			while (tmp->next)
				tmp = tmp->next;
			return (tmp);
		}
	public:
		void print()
		{
			this->print((int)this->size());
		}
		void print(int size)
		{
			std::cout << "head = " << this->_head << " | tail = " << this->_tail << "\n\n";
			ListIterator<value_type> it = this->begin();
			for (int i = 0; i < size; i++)
			{
				std::cout << "(" << i + 1 << ")\t- " << "[" << *it << "]\t - " << it.ptr << " ----> " << it.ptr->next <<"\n";
				if (it == head)
				it++;
			}
		}
};

#endif // LIST_HPP




// (1) list 1
// (2) size