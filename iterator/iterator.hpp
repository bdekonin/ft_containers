/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/22 15:43:53 by bdekonin      ########   odam.nl         */
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
class random_access_iterator: public iterator<random_access_iterator_tag ,T>
{
    
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