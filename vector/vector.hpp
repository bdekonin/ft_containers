/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:53:29 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/21 11:14:37 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

# include "../node/node.hpp"
# include "../node/DoubleLinkedList.hpp"

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

	Vector()
	{};
};

#endif // VECTOR_HPP