/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:30:22 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/06 15:31:10 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <iostream> 

/*
** Class vs Struct
**
** https://stackoverflow.com/questions/1127396/struct-constructor-in-c
*/

template<typename T>
struct Node
{
	/* Variable */
	Node	*prev;
	Node	*next;

	T		content;
	/* Constructor */
	Node(Node *_prev, Node *_next)
	: prev(_prev), next(_next)
	{
	}
	Node(Node *_prev, Node *_next, T _content)
	: prev(_prev), next(_next), content(_content)
	{
	}
	Node(T _content)
	: prev(nullptr), next(nullptr), content(_content)
	{
	}
	Node()
	: prev(nullptr), next(nullptr)
	{
	}
	/* Operator Overloading */
	Node	&operator=(const Node &rhs)
	{
		if (this != rhs)
		{
			this->prev = rhs.prev;
			this->next = rhs.next;
			this->content = rhs.content;
		}
		return *this;
	}
	bool	operator==(const Node &rhs) const
	{
		return (this->prev == rhs.prev &&
			this->next == rhs.next &&
			this->content == rhs.content);
	}
	bool	operator!=(const Node& rhs) const
	{
		return *this != rhs;
	}
	
	/* Methods */
	Node *getNext() {
		return this->next;
	}
	Node *getPrev() {
		return this->prev;
	}
};


#endif // NODE_HPP