/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:41:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/09 16:00:26 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "../Node/Node.hpp"

template <typename T>
class ListIterator
{
	public: /* Typedef */
		typedef ListIterator<T>					this_type;
		typedef T											value_type;
		typedef ptrdiff_t									difference_type;
		typedef T											*pointer;
		typedef Node<T>										*node_pointer; // pointer to list of node
		typedef T											&reference;
		
	public : /* Variables */
		node_pointer		ptr;
	
	public: /* Constructors */
		ListIterator()
		: ptr(nullptr)
		{	}
		ListIterator(node_pointer pointer)
		: ptr(pointer)
		{	}
		~ListIterator()
		{	}

	public: /* Operator Overloading */
		this_type	&operator=(const this_type &rhs)
		{
			this->ptr = rhs.ptr;
			return *this;
		}
		reference	operator*() const
		{
			return *this->ptr->content;
		}
		pointer		operator->() const
		{
			return &(this->ptr->content);
		}
		this_type	&operator++(int)
		{
			this->ptr = this->ptr->getNext();
			return *this;
		}
		this_type	&operator--(int)
		{
			this->ptr = this->ptr->getPrev();
			return *this;
		}
		friend inline bool operator==(const ListIterator<T> &lhs, const ListIterator<T> &rhs)
		{
			return (lhs.ptr == rhs.ptr);
		}
		friend inline bool operator!=(const ListIterator<T> &lhs, const ListIterator<T> &rhs)
		{
			return (lhs.ptr != rhs.ptr);
		}
};

#endif // LISTITERATOR_HPP