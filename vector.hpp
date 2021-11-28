
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

# include <iostream>
# include "iterator.hpp"
# include "utils.hpp"
# include <memory>



/* TODO
const iterator it = vec.begin();

*/

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{
	public: //  Member types
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
	
		typedef ft::random_access_iterator<value_type>						iterator;
		typedef ft::random_access_iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<value_type>							reverse_iterator;
		typedef ft::reverse_iterator<const value_type>						const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; 
		typedef typename allocator_type::size_type							size_type;

	/* Constructors */
		/* Default */
		vector(const allocator_type &alloc = allocator_type())
		: _alloc(alloc), _begin(nullptr), _size(0), _capacity(0)
		{	}
		/* Fill */
		vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _begin(nullptr), _size(0), _capacity(0)
		{
			// this->insert(this->begin(), n, val);
			this->reserve(n);
			while (n)
			{
				this->push_back(val);
				n--;
			}
		}
		/* Range */
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		: _alloc(alloc), _begin(nullptr), _size(0), _capacity(0)
		{
			if (last - first < 0)
				return ;
			this->assign(first, last);
		}
		/* Copy */
		vector (const vector &x)
		: _alloc(x._alloc), _begin(nullptr), _size(0), _capacity(0)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}
	
	/* Destructor */
		/* Vector destructor */
		~vector()
		{
			if (this->_begin)
				this->_alloc.deallocate(this->_begin, this->_capacity);
			this->_begin = nullptr;
		}

	/* Operator overloading */
		/* Operator = */
		vector &operator=(const vector& x)
		{
			this->_alloc = x._alloc;
			this->_begin = nullptr;
			this->_size = 0;
			this->_capacity = 0;
			this->insert(this->begin(), x.begin(), x.end());
			return *this;
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

	/* Capacity */
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
			while (n < this->_size)
				this->pop_back();
			if (n > this->_capacity)
				this->reserve(n);
			while (n > this->_size)
				push_back(val);
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
			if (new_cap <= this->_capacity)
				return ;
			// if (new_cap != 0)
			// 	new_cap = this->_capacity * 2;
			pointer tmp = this->_alloc.allocate(new_cap);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&(tmp[i]), this->_begin[i]);
			if (this->_begin)
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.destroy(&(this->_begin[i])); // destroys old element
					this->_begin[i] = value_type(); // sets old object to default
				}
				this->_alloc.deallocate(this->_begin, this->_capacity);
			}
			this->_begin = tmp;
			this->_capacity = new_cap;
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
			if (n >= this->size()) // of wel > ? staat op https://www.cplusplus.com/reference/vector/vector/at/ dat het >= moet zijn
				throw std::out_of_range("vector");
			return this->_begin[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range("vector");
			return this->_begin[n];
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
			return this->_begin[this->_size - 1];
		}
		const_reference back() const
		{
			return this->_begin[this->_size - 1];
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
		/* Assign vector content */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			this->clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		void assign (size_type n, const value_type& val)
		{
			this->clear();
			while (n)
			{
				this->push_back(val);
				n--;
			}
		}

		/* PUSH_BACK */

		/* Delete last element */
		void pop_back()
		{
			this->_alloc.destroy(&(this->_begin[this->_size - 1])); // destroys the object
			this->_begin[this->_size - 1] = value_type(); // initiliaze the object to default value so string is ""
			this->_size--;
		}

		/* INSERT */

		/* Erase elements */
		iterator erase (iterator position)
		{
			iterator temp(position);
			iterator it_end = this->end() - 1;
			while (position != it_end)
			{
				*position = *(position + 1);
				position++;
			}
			this->_size--;
			return (temp);
		}
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
				--last;
			}
			return first;
		}
		/* Swap content */
		void swap (vector &x)
		{
			pointer tempPointer;
			size_type tempSize;
			size_type tempCapacity;

			tempPointer = x._begin;
			tempSize = x._size;
			tempCapacity = x._capacity;

			x._begin = this->_begin;
			x._size = this->_size;
			x._capacity = this->_capacity;

			this->_begin = tempPointer;
			this->_size = tempSize;
			this->_capacity = tempCapacity;
		}
		/* Clear content */
		void clear()
		{
			while(this->_size)
				this->pop_back();
		}
	private: // maybe protected?
		allocator_type		_alloc;
		pointer				_begin;
		size_type			_size;
		size_type			_capacity;
	
	public:

		/* Add element at the end */
		void push_back (const value_type &val)
		{
			if (this->_size == this->_capacity)
			{
				if (this->_size == 0)
					reserve(1);
				else
					reserve(this->_capacity * 2);
			}
			this->_alloc.construct(&(this->_begin[this->_size]), val); // LEAKIE LEAK
			this->_size++;
		}
			/* Insert elements */
		iterator insert (iterator position, const value_type &val)
		{
			this->insert(position, 1, val);
			return iterator(this->_begin + ft::distance(this->begin(), position));
		}
		void insert (iterator position, size_type n, const value_type &val)
		{
			vector temp(position, this->end());
			this->_size -= ft::distance(position, this->end());

			while (n)
			{
				push_back(val);
				n--;
			}
			iterator it = temp.begin();
			while (it != temp.end())
			{
				this->push_back(*it);
				it++;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			vector temp(position, this->end());
			this->_size -= ft::distance(position, this->end());

			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
			iterator it = temp.begin();
			while (it != temp.end())
			{
				this->push_back(*it);
				it++;
			}
		}
};

template< class T, class Alloc>
bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	if (lhs.size() == rhs.size())
	{
		for (int i = 0; i != (int)lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}
	return false;
}
template< class T, class Alloc>
bool operator != (const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
	{
		for (int i = 0; i != (int)lhs.size(); i++)
			if (lhs[i] == rhs[i])
				return true;
		return false;
	}
	return true;
}
template< class T, class Alloc>
bool operator<(const std::vector<T, Alloc> &lhs, const std::vector<T, Alloc> &rhs)
{
	if (lhs.size() < rhs.size())
		return true;

	return false;
}


template < class T >
std::ostream& operator << (std::ostream &os, const ft::vector<T> &v) 
{
    os << "[";
    for (typename ft::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << " ]";
    return os;
}
}

#endif // VECTOR_HPP
