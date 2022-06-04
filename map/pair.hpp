/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:08:25 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/04/24 20:03:43 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{	
	/* https://www.cplusplus.com/reference/utility/pair/ */
	template < class T1, class T2 >
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		/* Constructors */
		pair()
		: first(), second()
		{
		}
		template<class U, class V>
		pair (const pair<U,V>& pr)
		: first(pr.first), second(pr.second)
		{
		}
		pair (const first_type &a, const second_type &b)
		: first(a), second(b)
		{
		}
		
		/* Destructor */
		~pair()
		{
		}

		/* Copy Overload */
		pair &operator= (const pair &pr)
		{
			first = pr.first;
			second = pr.second;

			return *this;
		}
	};

	/* https://www.cplusplus.com/reference/utility/make_pair/ */
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}	

		template <class T1, class T2>
		bool operator== (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}
		template <class T1, class T2>
		bool operator<  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
		}
		template <class T1, class T2>
		bool operator!= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (!(lhs == rhs));
		}
		template <class T1, class T2>
		bool operator<= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (!(rhs < lhs));
		}
		template <class T1, class T2>
		bool operator>  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (rhs < lhs);
		}
		template <class T1, class T2>
		bool operator>= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (!(lhs < rhs));
		}


	/* Overload the << operator */
	template <class T1, class T2>
	std::ostream &operator<< (std::ostream &os, const ft::pair<T1,T2>& pr)
	{
		os << "(" << pr.first << ", " << pr.second << ")";
		return os;
	}
}

#endif // PAIR_HPP