
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

# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{
	public: //  Member types
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
	
		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<value_type>							reverse_iterator;
		typedef ft::reverse_iterator<const value_type>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; 
		typedef typename allocator_type::size_type						size_type;

	vector(const allocator_type &alloc = allocator_type())
	: _begin(nullptr), _size(0), _capacity(0), _alloc(alloc)
	{
	};
	vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
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

	// template <class InputIterator>
	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	// {

	// }

	// vector (const vector& x)
	// {

	// }

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
			return reverse_iterator(this->_begin + this->_size - 1);
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->_begin + this->_size);
		}
		/* Return reverse iterator to reverse end */
		reverse_iterator rend()
		{
			return reverse_iterator(this->_begin - 1);
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















		/* Resizes the container so that it contains n elements. */
		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->size())
			{
				while (n != this->size())
					this->pop_back();
				return ;
			}

			if (n > this->capacity())
			{
				pointer new_begin;

				// WIP

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

			if (n > this->size())
			{

				for (int i = this->size(); i < (int)n; i++)
				{
					*(this->_begin + i) = val;
					this->_size++;
				}

			}
			return;

			// times * 2

			// protects
			if (n < this->size())
			{
				this->_size = n;
			}
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
			
			if (new_cap == 0)
				return ;
			if (new_cap <= this->capacity())
				return ;
			if (new_cap > this->max_size())
				throw std::length_error("vector::reserve");

			new_begin = new value_type[new_cap];

			for (int i = 0; i < new_cap; i++)
				new_begin[i] = value_type();

			if (!this->empty())
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
	/* Element Access */
		reference operator[](size_type n)
		{
			return *(this->_begin + n);
		}
		const_reference operator[](size_type n) const
		{
			return *(this->_begin + n);
		}
		reference at (size_type n)
		{
			return this[n];
		}
		const_reference at (size_type n) const
		{
			return this[n];
		}
		reference front()
		{
			return *this->begin();
		}
		const_reference front() const
		{
			return *this->begin();
		}
		reference back()
		{
			return *this->end();
		}
		const_reference back() const
		{
			return *this->end();
		}
		// value_type *data() noexcept
		// {
		// 	return this->_begin;
		// }
		// const value_type *data() const noexcept
		// {
		// 	return this->_begin;
		// }
	
	/* Modifiers */
		void pop_back()
		{
			this->_size--;
		}
		iterator insert (iterator position, const value_type &val)
		{
			this->insert(position, 1, val);
			return this->begin();
		}
		void insert (iterator position, size_type n, const value_type &val)
		{
			size_type index = &(*position) - this->_begin;

			if (this->size() + n <= this->capacity())
				;
			else if ((this->size() + n) > this->capacity() * 2)
				this->reserve(this->size() + n);
			else
				this->reserve((this->capacity()) * 2);

			for (; n > 0; n--)
			{
				for (int i = this->size(); i > index; i--)
					this->_begin[i] = this->_begin[i - 1];
				this->_size++;
				this->_begin[index] = val;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			(
				this->insert(position, *first);
				first++;
			)
		}

			

// return this->end();


// 			if (n + this->size() > this->capacity()) // check total size
// 				this->reserve(this->capacity() * 2);

			

// 			for (int j = 0; j < n; j++)
// 			{
// 				for (int i = this->size(); i >= 0; i--)
// 					this->_begin[i + 1] = this->_begin[i];
// 				this->_begin[0] = val; // val
// 			}
// 			// this->_size += 5;
// 			return this->end();
// 		}

		
	private:
		allocator_type		_alloc;
		pointer				_begin;
		size_type			_size;
		size_type			_capacity;
};
}

#endif // VECTOR_HPP