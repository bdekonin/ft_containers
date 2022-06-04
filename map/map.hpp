/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 11:09:54 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/04/26 11:25:37 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "pair.hpp"
# include "AVL.hpp"
# include "iterator.hpp"


namespace ft
{
	
template < class Key,										// map::key_type
		class T,											// map::mapped_type
		class Compare = std::less<Key>,						// map::key_compare
		class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
		>
class map
{
	private:
		int _size;
	public: // Member Types
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<Key, T>									value_type;	// TODO change to [typedef ft::pair<const Key, T>								value_type;]
		typedef Compare													key_compare; // Defaults to: less<key_type>
		// typedef Compare													value_compare; // change -> https://www.cplusplus.com/reference/map/map/value_comp/
		typedef Alloc													allocator_type; // Defaults to: std::allocator<value_type>

	protected:
		class AVL_key_compare
		{
			public:
				bool operator()(const value_type& lhs, const value_type& rhs) const
				{
					return (key_compare()(lhs.first, rhs.first));
				}
				bool operator()(const key_type& lhs, const key_type& rhs) const
				{
					return (key_compare()(lhs, rhs));
				}
		};

	public:

		typedef MAP_AVL<key_type, mapped_type, AVL_key_compare, allocator_type>					tree_type;
		typedef typename MAP_AVL<key_type, mapped_type, AVL_key_compare, allocator_type>::node			node_type;

		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		// typedef typename ft::bidirectional_iterator<node_type>	iterator;
		// typename typename ft::bidirectional_iterator<const value_type> const_iterator;
		// typedef typename ft::reverse_iterator<iterator> iterator;
		// typedef typename ft::reverse_iterator<const_iterator> const_iterator;
		// typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; 
		// typedef typename allocator_type::size_type							size_type;

		tree_type _tree;


		class value_compare
		{
			friend class map;
			
			protected:
			
				key_compare comp;
				
				value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

			public:
			
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

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
	/* Destructors */
		~map()
		{

		}


	/* TEMP */
	// iterator begin()
	// {
	// 	return iterator(_tree.begin());
	// }

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
