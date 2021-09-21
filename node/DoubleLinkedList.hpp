/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DoubleLinkedList.hpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 09:45:41 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/21 14:47:17 by bdekonin      ########   odam.nl         */
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
		: _head(nullptr), _tail(nullptr)
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

        // Methods
        // void push_back(Node<T> *val) /* Add element at the end */
        // {
        // }

        void push_front(T new_data)
        {
            /* 1. allocate node */
            Node<T> *new_node = new Node<T>(new_data);

            /* 2. Make next of new node as head
            and previous as NULL */
            new_node->_next = this->_head;
            new_node->_prev = NULL;

            /* 3. change prev of head node to new node */
            if (this->_head != NULL)
                this->_head->_prev = new_node;
                
            /* 4. move the head to point to the new node */
            this->_head = new_node;
        }
        void push_back(T new_data)
        {
            /* 1. allocate node */
            Node<T> *new_node = new Node<int>(new_data);

            if (this->_head == NULL)
            {   
                this->_head = new_node;
                return ;
            }
            // else
            //     this
            
            new_node->_prev = this->_tail;
            this->_tail->_next = new_node;
        }
        Node<T> *getHead()
        {
            return this->_head;
        }
    private:
        Node<T> *_head;
		Node<T> *_tail;
};

#endif // DOUBLELINKEDLIST_HPP
