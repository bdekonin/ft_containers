/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/21 12:47:44 by bdekonin      ########   odam.nl         */
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

template< class Category,
	class T,
	class Distance = std::ptrdiff_t,
	class Pointer = T*,
	class Reference = T& >
class iterator
{
	public:
		typedef T               value_type;
		typedef Distance        difference_type;
		typedef Pointer         pointer;
		typedef Reference       reference;
		typedef Category        iterator_category;
};
template <typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
	/* Typedefs */
	public:
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename iterator<random_access_iterator_tag, T>::value_type            value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type       difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer               pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference             reference;
	private:
		pointer _value;

	/* Constructors */
	public:
		random_access_iterator(void)
		: _value(nullptr)
		{
		}
		random_access_iterator(pointer val)
		: _value(val)
		{
		}
		random_access_iterator(random_access_iterator const &src)
		: _value(src._value)
		{
		}

		virtual ~random_access_iterator(void)
		{
		}
		
		random_access_iterator &operator = (random_access_iterator const &rhs)
		{
			if (this == &rhs)
				return *this;

			this->_val = rhs._val;
			return *this;
		}

	/* Operator Overloading */
	public:
		value_type			&operator * (void) { return *this->_value; }
		random_access_iterator	&operator ++ (void) { this->_value++; return *this; }
		random_access_iterator	&operator -- (void) { this->_value--; return *this; }
		random_access_iterator operator++(int) { random_access_iterator ret = *this; this->operator++(); return ret; }
		random_access_iterator operator--(int) { random_access_iterator ret = *this; this->operator--(); return ret; }
		bool		operator == (random_access_iterator const &rhs) { return this->_value == rhs._value; }
		bool		operator != (random_access_iterator const &rhs) { return this->_value != rhs._value; }
		bool		operator < (random_access_iterator const &rhs) { return this->_value < rhs._value; }
		bool		operator > (random_access_iterator const &rhs) { return this->_value > rhs._value; }
		bool		operator <= (random_access_iterator const &rhs) { return this->_value <= rhs._value; }
		bool		operator >= (random_access_iterator const &rhs) { return this->_value >= rhs._value; }
		random_access_iterator	operator += (int const &value) { this->_value += value; return *this; }
		random_access_iterator	operator -= (int const &value) { this->_value -= value;	return *this; }
		random_access_iterator	operator + (int const &value) { return this->_value + value; }
		random_access_iterator	operator - (int const &value) { return this->_value - value; }
		value_type			&operator [] (int i) { return *(this->_value + i) ; }
};
template<typename T>
class reverse_iterator: public iterator<bidirectional_iterator_tag, T>
{
	/* Typedefs */
	public:
		typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename iterator<bidirectional_iterator_tag, T>::value_type            value_type;
		typedef typename iterator<bidirectional_iterator_tag, T>::difference_type       difference_type;
		typedef typename iterator<bidirectional_iterator_tag, T>::pointer               pointer;
		typedef typename iterator<bidirectional_iterator_tag, T>::reference             reference;

	private:
		pointer _value;

	/* Constructors */
	public:
		reverse_iterator(void)
		: _value(nullptr)
		{
		}
		reverse_iterator(pointer val)
		: _value(val)
		{
		}
		reverse_iterator(reverse_iterator const &src)
		: _value(src._value)
		{
		}
		virtual ~reverse_iterator(void)
		{
		}
		reverse_iterator &operator = (reverse_iterator const &rhs)
		{
			if (this == &rhs)
				return *this;

			this->_val = rhs._val;
			return *this;
		}

	/* Operator Overloading */
	public:
		value_type			&operator * (void) { return *this->_value; }
		reverse_iterator	&operator ++ (void) { this->_value--; return *this; }
		reverse_iterator	&operator -- (void) { this->_value++; return *this; }
		reverse_iterator operator++(int) { reverse_iterator ret = *this; this->operator++(); return ret; }
		reverse_iterator operator--(int) { reverse_iterator ret = *this; this->operator--(); return ret; }
		bool		operator == (reverse_iterator const &rhs) { return this->_value == rhs._value; }
		bool		operator != (reverse_iterator const &rhs) { return this->_value != rhs._value; }
		bool		operator < (reverse_iterator const &rhs) { return this->_value < rhs._value; }
		bool		operator > (reverse_iterator const &rhs) { return this->_value > rhs._value; }
		bool		operator <= (reverse_iterator const &rhs) { return this->_value <= rhs._value; }
		bool		operator >= (reverse_iterator const &rhs) { return this->_value >= rhs._value; }
		reverse_iterator	operator += (int const &value) { this->_value += value; return *this; }
		reverse_iterator	operator -= (int const &value) { this->_value -= value;	return *this; }
		reverse_iterator	operator + (int const &value) { return this->_value + value; }
		reverse_iterator	operator - (int const &value) { return this->_value - value; }
};
/*
** https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait
*/
template <class iterator>
struct iterator_traits
{
	typedef typename iterator::difference_type       difference_type;
	typedef typename iterator::value_type            value_type;
	typedef typename iterator::pointer               pointer;
	typedef typename iterator::reference             reference;
	typedef typename iterator::iterator_category     iterator_category;
};
template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::difference_type res;

			res = 0;
			while (first != last)
			{
				res++;
				first++;
			}
			return res;
		}

}

#endif // ITERATOR_HPP
