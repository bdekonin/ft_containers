/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/20 14:44:49 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
# include "Tags.hpp"

template< class Category, class T, class Distance = std::ptrdiff_t,
    class Pointer = T*, class Reference = T& >
class iterator
{
    public:
        typedef Category        iterator_catagory;
        typedef T               value_type;
        typedef Distance        difference_type;
        typedef Pointer         pointer;
        typedef Reference       reference;
};


template <typename T>
class random_access_iterator: public ::iterator<random_access_iterator_tag ,T>
{
    
};
template<typename T>
class reverse_iterator: public ::iterator<random_access_iterator_tag, T>
{
    
};
template<typename T>
class iterator_traits: public ::iterator<>, T>
{
    
};

#endif // ITERATOR_HPP