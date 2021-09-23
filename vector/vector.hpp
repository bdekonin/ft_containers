/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:53:29 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/23 20:58:26 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

# include "../node/node.hpp"
# include "../node/DoubleLinkedList.hpp"

#define STARTING_CAPACITY 4

template < class T, class Alloc = std::allocator<T> >
class Vector
{
	public: //  Member types
		typedef T                                           	value_type;
		typedef Alloc                                       	allocator_type;
		typedef typename allocator_type::reference          	reference;
		typedef typename allocator_type::const_reference    	const_reference;
		typedef typename allocator_type::pointer            	pointer;
		typedef typename allocator_type::const_pointer      	const_pointer;
	
		typedef ::random_access_iterator<value_type>        	iterator;
		typedef ::random_access_iterator<const value_type>    	const_iterator;
		typedef ::reverse_iterator<iterator>             		reverse_iterator;
		typedef ::reverse_iterator<const_iterator>      		const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type    difference_type; 
		typedef typename allocator_type::size_type          	size_type;

	Vector(const allocator_type &alloc = allocator_type())
	: _begin(nullptr), _end(nullptr), _capacity(nullptr), _alloc(alloc)
	{
	};
	
	size_type	capacity(void) const
	{
		return _capacity - _begin;
	}
	size_type	size(void) const
	{
		return _end - _begin;
	}
	/*
	** https://www.cplusplus.com/reference/vector/vector/reserve/
	*/
	void reserve (size_type n) /* Requests that the vector capacity be at least enough to contain n elements. */
	{
		pointer oldStart = this->_begin;
		pointer oldEnd = this->_end;
		size_type oldN = this->size();
		size_type oldCap = this->capacity();

		this->_begin = this->_alloc.allocate(n);
		this->_end = this->_begin;
		this->_capacity = this->_begin + n;

		while (oldStart != oldEnd)
			this->_alloc.construct(this->_end++, *oldStart++);
		this->_alloc.deallocate(oldStart - oldN, oldCap);
	}

	void fill(size_type n)
	{
		for (size_type i = 0; i < n; i++)
			this->_begin[i] = i;
	}
	private:
		// pointer	_listarray; /* https://en.wikipedia.org/wiki/Dynamic_array */
		allocator_type	_alloc;
		pointer			_begin;
		pointer			_end;
		pointer			_capacity;
};

#endif // VECTOR_HPP