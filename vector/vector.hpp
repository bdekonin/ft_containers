/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:53:29 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/24 11:30:22 by bdekonin      ########   odam.nl         */
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
	Vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	: _begin(nullptr), _end(nullptr), _capacity(nullptr), _alloc(alloc)
	{
		this->_begin = this->_alloc.allocate(n);
		this->_end = this->_begin;
		this->_capacity = this->_begin + n;

		for (size_type i = 0; i < n; i++)
		{
			this->_begin[i] = val;
		}
	}


	/* Capacity */
		/* Return size. */
		size_type size() const
		{
			return this->_end - this->_begin;
		}
		/* Return maximum size */
		size_type max_size() const
		{
			return this->_alloc.max_size();
		}
		/* Resizes the container so that it contains n elements. */
		void resize(size_type n, value_type val = value_type())
		{
			pointer oldStart = this->_begin;
			pointer oldEnd = this->_end;
			size_type oldSize = this->size();
			size_type oldCap = this->capacity();

			// if (n <= this->capacity())
			// {
			// 	std::cout << "n is <= then the capacity" << std::endl;
			// 	return ;
			// }
			if (n < this->size())
			{
				while (this->size() > n)
				{
					--this->_end;
					this->_alloc.destroy(this->_end);
				}
			}
			else
			{
				// std::cout << "ja - " << n << "[" << val << "]\n";
				this->_begin = this->_alloc.allocate(n);
				this->_end = this->_begin + oldSize;
				this->_capacity = this->_begin + n;

				// printf("-----%d", n);

				for (size_type i = 0; i < this->size(); i++)
					this->_begin[i] = val; // fill entire thing
				for (size_type i = 0; i < oldCap; i++)
					this->_begin[i] = *(oldStart + i);
				this->_alloc.deallocate(oldStart, oldCap);
			}
		}


			// void        resize (size_type n, value_type val = value_type())
			// {
			// 	if (n > this->max_size())
			// 		throw (std::length_error("vector::resize"));
			// 	else if (n < this->size())
			// 	{
			// 		while (this->size() > n)
			// 		{
			// 			--_end;
			// 			_alloc.destroy(_end);
			// 		}
			// 	}
			// 	else
			// 		this->insert(this->end(), n - this->size(), val);
			// }


			
		/*Return ize of allocated storage capacity */
		size_type capacity() const
		{
			return this->_capacity - this->_begin;
		}


		/* temporary */
			void print(size_type const n) const
			{
				for (size_type i = 0; i < n; i++)
				{
					std::cout << ' ' << this->_begin[i];
				}
				std::cout  << std::endl;
			}
			void push_back (const value_type &val)
			{
				if (this->_end == this->_capacity)
				{
					// int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
					this->resize(this->capacity() + 1);
				}
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
			// void push_back (const value_type& val)
			// {                
			// 	if (_end == _end_capacity)
			// 	{
			// 		int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
			// 		this->reserve(next_capacity);
			// 	}
			// 	_alloc.construct(_end, val);
			// 	_end++;
			// }
	private:
		// pointer	_listarray; /* https://en.wikipedia.org/wiki/Dynamic_array */
		
		allocator_type	_alloc;
		pointer			_begin;
		pointer			_end;
		pointer			_capacity;
};

#endif // VECTOR_HPP