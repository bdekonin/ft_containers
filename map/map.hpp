/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 11:09:54 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/04/19 19:41:34 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "pair.hpp"


namespace ft
{
	
template < class Key,										// map::key_type
		class T,											// map::mapped_type
		class Compare = std::less<Key>,						// map::key_compare
		class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
		>
class map
{
	public: // Member Types
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<const Key, T>									value_type;	
		typedef Compare												key_compare; // Defaults to: less<key_type>
		typedef Compare												value_compare; // change -> https://www.cplusplus.com/reference/map/map/value_comp/
		typedef Alloc												allocator_type; // Defaults to: std::allocator<value_type>
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		// typedef typename ft::bidirectional_iterator<value_type>		iterator;
		// typename typename ft::bidirectional_iterator<const value_type> const_iterator;
		// typedef typename ft::reverse_iterator<iterator> iterator;
		// typedef typename ft::reverse_iterator<const_iterator> const_iterator;
		// typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; 
		// typedef typename allocator_type::size_type							size_type;

	/* Constructor */
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
			
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
		
		}
		map (const map& x)
		{
			
		}
	/* Destructors
		// temp

	/* Iterators*/
		// temp

	/* Capacity */
		// temp

	/* Element access */
		// temp

	/* Modifiers */
		// temp

	/* Observers */
		// temp

	/* Operations */
		// temp

	/* Allocator */
		// temp
};
}

#endif // MAP_HPP
