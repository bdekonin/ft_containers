/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/15 10:53:21 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/*
** https://www.cplusplus.com/reference/iterator/
*/

#include <iostream>
# include "Tags.hpp"

template< class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T& >
class iterator
{
	public:
		typedef Category        iterator_category;
		typedef T               value_type;
		typedef Distance        difference_type;
		typedef Pointer         pointer;
		typedef Reference       reference;
	public: /* Member Functions */
};


template <typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
	public:
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename iterator<random_access_iterator_tag, T>::value_type            value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type       difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer               pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference             reference;

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
	public:
		/* Input */
			bool operator==(const random_access_iterator &rhs)
			{
				return this->_value == rhs._value;
			}
			bool operator!=(const random_access_iterator &rhs)
			{
				return this->_value != rhs._value;
			}







		// /* https://stackoverflow.com/questions/28592798/i-have-problems-implementing-the-increment-operator */
		// random_access_iterator &operator++()
		// {
		// 	this->_value++;
		// 	return *this; // return new value by reference
		// }
		// random_access_iterator operator++(int)
		// {
		// 	random_access_iterator ret = *this;
		// 	this->operator++();
		// 	return ret; // return new value by reference
		// }
    	// reference operator*()
    	// {
    	//     return *this->_value;;
		// }

	private:
		pointer _value;
};
template<typename T>
class reverse_iterator: public iterator<random_access_iterator_tag, T>
{
	
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

#endif // ITERATOR_HPP