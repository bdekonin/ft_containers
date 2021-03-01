/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:03:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/01 15:52:47 by bdekonin      ########   odam.nl         */
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
	private:
		typedef typename List<T>::_node _node;
		
		_node *_n;
};


template <typename T>
class List
{
	public: // typedef
		typedef size_t size_type;
		typedef ListIterator<T> iterator;
	private:
		/*
		**	Double Linked List
		*/
		struct _node
		{
			struct _node	*next;
			struct _node	*prev;
			
			int				content;

			_node(_node *_prev, _node *_next)
				: prev(_prev), next(_next)
			{}
			_node(_node *_prev, _node *_next, int _content)
				: prev(_prev), next(_next), content(_content)
			{}
		};
		
		_node	*_head; // last
		_node	*_tail; // last _node
	
	public:
		/* Constructor  */
		List()
		{
			this->_head = new _node(nullptr, nullptr, 0);

		}

		/* Methods */
		void insert()
		{
			this->_head->next = new _node(this->_head, nullptr, 1);
			this->_head->next->next = new _node(this->_head->next, nullptr, 2);
			this->_head->next->next->next = new _node(this->_head->next->next, nullptr, 3);
			this->_head->next->next->next->next = new _node(this->_head->next->next->next, nullptr, 4);
		}

		void print()
		{
			_node *nodee = this->_head;

			while (nodee)
			{
				std::cout << nodee->content;
				nodee = nodee->next;
			}
		}
	private:
		template <typename _T>
		friend class ListIterator; // So ListIterator can access private rights
};

#endif // LIST_HPP