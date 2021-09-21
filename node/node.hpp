/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 08:26:32 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/21 09:45:49 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

template<typename T>
class Node
{
	public:
		/* Constructor  */
		Node(Node *next, Node *prev)
		: _next(next), _prev(prev)
		{
		}
		Node(Node *next, Node *prev, T content)
		: _next(next), _prev(prev), _content(content)
		{
		}
		Node(T content)
		: _next(nullptr), _prev(nullptr), _content(content)
		{
		}
		Node()
		: _next(nullptr), _prev(nullptr)
		{
		}
		/* Destructor */
		~Node()
		{
		}

		/* Copy constructor */
		Node(const Node&);

		/* Operation overload = */
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
		/* Operation overload == */
		bool	operator==(const Node &rhs) const
		{
			return (this->prev == rhs.prev &&
				this->next == rhs.next &&
				this->content == rhs.content);
		}
		/* Operation overload != */
		bool	operator!=(const Node& rhs) const
		{
			return *this != rhs;
		}
		
		// Methods
		Node *getNext()
		{
			return this->_next;
		}
		Node *getPrev()
		{
			return this->_prev;
		}
	public:
		Node    *_next;
		Node    *_prev;
		T		_content;
};

#endif // NODE_HPP