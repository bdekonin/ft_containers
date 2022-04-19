/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:08:25 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/04/19 18:38:50 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	/* https://www.cplusplus.com/reference/utility/make_pair/ */
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
	
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
		}
	};
}

#endif // PAIR_HPP