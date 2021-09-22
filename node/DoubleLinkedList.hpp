/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DoubleLinkedList.hpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 09:45:41 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/22 15:20:39 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLELINKEDLIST_HPP
# define DOUBLELINKEDLIST_HPP

#include "node.hpp"

template<typename T>
class DoubleLinkedList
{
	public:	
		/* Constructor  */
		DoubleLinkedList()
		: _head(nullptr)
		{
		}
		
		/* Destructor */
		~DoubleLinkedList()
		{
		}

		/* Copy constructor */
		DoubleLinkedList(const DoubleLinkedList &cp);

		/* Operation overload = */
		DoubleLinkedList& operator = (const DoubleLinkedList& e);

		/* Operation overload [] */
		Node<T> *operator [](size_t loc) const
		{
			Node<T> *temp = this->begin();
			for (size_t i = 0; i < loc; i++)
				temp = temp->_next;
			return (temp);
		}

		// Methods
		// void push_back(Node<T> *val) /* Add element at the end */
		// {
		// }
		Node<T> *begin() const
		{
			return this->_head;
		}
		Node<T> *end() const
		{
			Node<T> *temp = this->_head;

			while(temp->_next)
				temp = temp->_next;
			return (temp);
		}
		void push_front(Node<T> *newdata) /* Add element at the front */
		{
			newdata->_next = this->_head;
			if (this->_head)
				this->_head->_prev = newdata;
			this->_head = newdata;
		}
		void push_front(T newdata) /* Add element at the front */
		{
			Node<T> *newnode = new Node<T>(newdata);
			
			newnode->_next = this->_head;
			if (this->_head)
				this->_head->_prev = newnode;
			this->_head = newnode;
		}
		void push_back(Node<T> *newdata) /* Add element at the end */
		{
			Node<T> *tmp;

			if (!this->_head)
				this->push_front(newdata);
			else
			{
				tmp = this->end();
				tmp->_next = newdata;
				newdata->_prev = tmp;
			}
		}
		void push_back(T newdata) /* Add element at the end */
		{
			Node<T> *tmp;
			Node<T> *newnode = new Node<T>(newdata);

			if (!this->_head)
				this->push_front(newnode);
			else
			{
				tmp = this->end();
				tmp->_next = newnode;
				newnode->_prev = tmp;
			}
		}
		void pop_back() /* Delete last element */
		{
			Node<T> *node = this->end();

			this->unlink(node);
			this->del_one(node);
		}
		void insert(Node<T> *newnode, Node<T> *location) /* Insert elements */
		{
			if (!location)
			{
				this->push_back(newnode);
				return ;
			}
			if (location == this->_head)
			{
				this->push_front(newnode);
				return ;
			}
			newnode->_prev = location->_prev;
			newnode->_next = location;
			location->_prev = newnode;
			newnode->_prev->_next = newnode;
		}
	private:
		void del_one(Node<T> *node)
		{
			if (!node)
				return ;
			delete node;
		}
		Node<T> *unlink(Node<T> *node)
		{
			if (!node->_prev) // head
			{
				this->_head = node->_next;
				if (this->_head)
					this->_head->_prev = nullptr;
			}
			else if (!node->_next) // last
				node->_prev->_next = nullptr;
			else // middle
			{
				node->_prev->_next = node->_next;
				node->_next->_prev = node->_prev;
			}
			node->_prev = nullptr;
			node->_next = nullptr;
			return (node);
		}
		Node<T> *_head;
};

#endif // DOUBLELINKEDLIST_HPP
