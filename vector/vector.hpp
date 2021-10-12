
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:53:29 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/12 14:35:15 by bdekonin      ########   odam.nl         */
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
	: _begin(nullptr), _size(0), _capacity(0), _alloc(alloc)
	{
	};
	Vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	: _begin(nullptr), _size(0), _capacity(0), _alloc(alloc)
	{
		this->_begin = this->_alloc.allocate(n);
		this->_size = n;
		this->_capacity = n;

		for (size_type i = 0; i < n; i++)
		{
			this->_begin[i] = val;
		}
	}

	/* Iterators ✅ */ 
		/* return iterator to beginning */
		iterator begin()
		{
			return iterator(this->_begin);
		}
		const_iterator begin() const
		{
			return const_iterator(this->_begin);
		}
		/* return iterator to end */
		iterator end()
		{
			return iterator(this->_begin + this->_size);
		}
		const_iterator end() const
		{
			return const_iterator(this->_begin + this->_size);
		}
		/* return reverse iterator to reverse beginning */
		reverse_iterator rbegin()
		{
			return reverse_iterator(this->_begin + this->_size);
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->_begin + this->_size);
		}
		/* Return reverse iterator to reverse end */
		reverse_iterator rend()
		{
			return reverse_iterator(this->_begin);
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->_begin);
		}
		/* return const_iterator to beginning */
		const_iterator cbegin() const
		{
			return const_iterator(this->_begin);
		}
		/* return const_iterator to end */
		const_iterator cend() const
		{
			return const_iterator(this->_begin + this->_size);
		}		
		/* return const_reverse_iterator to reverse beginning */
		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(this->_begin + this->_size);
		}
		/* return const_reverse_iterator to reverse end */
		const_iterator crend() const
		{
			return const_iterator(this->_begin);
		}


 /*
	https://stackoverflow.com/questions/7397768/choice-between-vectorresize-and-vectorreserve

 */
	/* Capacity ❌ */
		/* Return size. */
		size_type size() const
		{
			return _size;
		}
		/* Return maximum size */
		size_type max_size() const
		{
			return this->_alloc.max_size();
		}
		/* Reiszes the container so that it contains n elements. */
		void resize(size_type n, value_type val = value_type())
		{

			// protects
			if (n < this->size())
			{
				this->_size = n;
			}


			// bigger > size
			pointer new_begin;
			
			new_begin = new value_type[n];
			
			for (size_type i = 0; i < n; i++)
				new_begin[i] = val;
			for (size_type i = 0; i < this->size(); i++)
				new_begin[i] = this->_begin[i];

			delete [] this->_begin;

			this->_begin = new_begin;
			this->_capacity = n;
			this->_size = n;
		}
		/* Return size of allocated storage capacity */
		size_type capacity() const
		{
			return this->_capacity;
		}
		/* Test wether vector is empty */
		bool empty() const
		{
			return this->_size == 0;
		}
		/* Reserves storage */
		void reserve(size_type new_cap)
		{
			pointer new_begin;

			if (new_cap <= this->capacity())
				return ;
			if (new_cap > this->max_size())
				throw std::length_error("vector::reserve");

			new_begin = new value_type[new_cap];
			
			if (this->_begin) // copy elements
			{
				pointer p1 = new_begin;
				pointer p2 = this->_begin;
				
				for (int i = 0; i < (int)this->size(); i++, p1++, p2++)
					*p1 = *p2;
			}
			delete [] this->_begin;

			this->_begin = new_begin;
			this->_capacity = new_cap;
		}
		/* Shrink to fit */
		void shrink_to_fit()
		{
		}


	/* Modifiers */


		/* temporary */
			void print(size_type const n) const
			{

				for (size_type i = 0; i < n; i++)
				{
					std::cout << ' ' << this->_begin[i];
				}
				std::cout << "\t\t\t| " << this->capacity() << " " << this->size();
				std::cout  << std::endl;
			}
	private:
		allocator_type		_alloc;
		pointer				_begin;
		size_type			_size;
		size_type			_capacity;
};

#endif // VECTOR_HPP