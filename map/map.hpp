/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 11:09:54 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/01/25 12:27:37 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>

namespace ft
{
	
template < class Key,										// map::key_type
		class T,											// map::mapped_type
		class Compare = std::less<Key>,						// map::key_compare
		class Alloc = std::allocator<pair<const Key,T> >	// map::allocator_type
		> class map
{
	public: // Member Types
		typedef Key					key_type;
		typedef T					mapped_type;
		typedef pair<const Key, T>	value_type;	
		typedef Compare				key_compare;
		
		
};

template < class T1, class T2 >
struct pair;

}

#endif // MAP_HPP
