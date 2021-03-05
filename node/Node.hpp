/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:30:22 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/05 17:39:28 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

template<typename T>
class Node
{
	public:
		/* Variable */
		Node	*prev;
		Node	*next;

		T		content;
		/* Constructor */
		Node(Node *_prev, Node *_next)
		: prev(_prev), next(_next), content(nullptr)
		{
		}
		Node(Node *_prev, Node *_next, T _content)
		: prev(_prev), next(_next), content(content)
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
				this->next == rhs.next
				this->content == rhs.content)
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
		Node *getContent() {
			return this->content
		}
		
};

#endif // NODE_HPP