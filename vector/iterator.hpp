/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/12/01 22:33:53 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/*
** https://www.cplusplus.com/reference/iterator/
*/

# include <iostream>

# include "utils.hpp"

namespace ft {

template< class Category, class T, class Pointer = T*, class Reference = T&, class Distance = std::ptrdiff_t >
class iterator
{
	public:
		typedef T               value_type;
		typedef Distance        difference_type;
		typedef Pointer         pointer;
		typedef Reference       reference;
		typedef Category        iterator_category;
	public:
		/* Constructors */
		iterator() : _value(nullptr) { }
		iterator(pointer val) : _value(val) { }
		iterator(iterator const &src) { *this = src; }

		/* Destructor */
		virtual ~iterator() { }

		/* Operators */
		iterator	&operator=(iterator const &src)
		{
			this->_value = src._value;
			return (*this);
		}

	protected:
		pointer _value;
};

template < class T, class Category = ft::bidirectional_iterator_tag >
class bidirectional_iterator : public iterator<Category, T>
{
	public:
		typedef Category								iterator_category;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::ptrdiff_t							difference_type;

	/* Constructors */
	public:
		bidirectional_iterator() : iterator<Category, T>() { }
		bidirectional_iterator(pointer val) : iterator<Category, T>(val) { }

		/* Destructors */
		virtual ~bidirectional_iterator() { }
		
		/* Operators */
		bidirectional_iterator &operator = (bidirectional_iterator const &rhs)
		{
			if (this == &rhs)
				return *this;
			// pointer
			this->_value = rhs._value;
			return *this;
		}
	/* Operator Overloading */
	public:
		bool		operator == (bidirectional_iterator const &rhs) { return this->_value == rhs._value; } // a ==
		bool		operator != (bidirectional_iterator const &rhs) { return this->_value != rhs._value; } // a !=
		value_type	&operator * (void) { return *this->_value; } // a*
		value_type	*operator -> (void) { return this->_value; } // a->
		bidirectional_iterator	&operator++() { this->_value++; return (*this); } // ++a
		bidirectional_iterator	operator++(int) { bidirectional_iterator old = *this; this->_value++; return (old); } // a++
		bidirectional_iterator	&operator--(void) { this->_value--; return (*this); } // --a
		bidirectional_iterator	operator--(int) { bidirectional_iterator old = *this; this->_value--; return (old); } // a--
};

template < class T, class Category = ft::random_access_iterator_tag>
class random_access_iterator : public bidirectional_iterator<T, Category>
{
	public:
		typedef Category								iterator_category;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::ptrdiff_t							difference_type;

	/* Constructors */
	public:
		random_access_iterator() : bidirectional_iterator<T, Category>() { }
		random_access_iterator(pointer val) : bidirectional_iterator<T, Category>(val) { }
		random_access_iterator(random_access_iterator const &src) { *this = src; }

		/* Destructors */
		virtual ~random_access_iterator() { }
		
		/* Operators */
		random_access_iterator &operator = (random_access_iterator const &rhs)
		{
			if (this == &rhs)
				return *this;

			this->_value = rhs._value;
			return *this;
		}
	/* Operator Overloading */
	public:
		random_access_iterator	operator +		(difference_type const &value) { return this->_value + value; }
		difference_type			operator +		(random_access_iterator const &rhs) { return this->_value + rhs._value; }
		random_access_iterator	operator -		(difference_type const &value) { return this->_value - value; }
		difference_type			operator -		(random_access_iterator const &rhs) { return this->_value - rhs._value; }
		bool					operator <		(random_access_iterator const &rhs) { return this->_value < rhs._value; }
		bool					operator >		(random_access_iterator const &rhs) { return this->_value > rhs._value; }
		bool					operator <= 	(random_access_iterator const &rhs) { return this->_value <= rhs._value; }
		bool					operator >= 	(random_access_iterator const &rhs) { return this->_value >= rhs._value; }
		random_access_iterator	operator += 	(int const &value) { this->_value += value; return *this; }
		random_access_iterator	operator -= 	(int const &value) { this->_value -= value;	return *this; }
		value_type				&operator [] 	(int i) { return *(this->_value + i) ; }
};

template <class Iterator>
class reverse_iterator
{
	public:
		typedef Iterator															iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category			iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type					value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type				difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer						pointer;
		typedef typename ft::iterator_traits<Iterator>::reference					reference;
	private:
		iterator_type	_value;

	/* Constructors */
	public:
		reverse_iterator()
		: _value(nullptr) { }
		reverse_iterator (iterator_type it)
		: _value(it) { }
		reverse_iterator (const reverse_iterator<Iterator> &rev_it)
		: _value(rev_it.base()) { }

		/* Destructors */
		virtual ~reverse_iterator(void) { }
		
		/* Operators */
		reverse_iterator &operator = (reverse_iterator const &rhs)
		{
			if (this == &rhs)
				return *this;

			this->_value = rhs._value;
			return *this;
		}
	/* Operator Overloading */
	public:
		iterator_type base() const { return this->_value; }
		reference	operator*() const { iterator_type tmp = this->_value; return *--tmp; }
		pointer operator->() const { return &(operator*()); }
		reverse_iterator<iterator_type> &operator++() { --this->_value; return (*this); }
		reverse_iterator<iterator_type> operator++(int) { reverse_iterator<iterator_type> old = *this; --this->_value; return (old); }
		reverse_iterator<iterator_type> &operator--() { ++this->_value; return (*this); }
		reverse_iterator<iterator_type> operator--(int) { reverse_iterator<iterator_type> old = *this; ++this->_value; return (old); }
		reference operator[](difference_type n) const { return *(this->_value - n); }
		reverse_iterator<iterator_type> operator+(difference_type n) const { return (this->_value - n); }
		reverse_iterator<iterator_type> operator-(difference_type n) const { return (this->_value + n); }
		reverse_iterator<iterator_type> &operator+=(difference_type n) { this->_value -= n; return (*this); }
		reverse_iterator<iterator_type> &operator-=(difference_type n) { this->_value += n; return (*this); }
};


} // namespace ft

#endif // ITERATOR_HPP
