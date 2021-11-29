/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 12:36:57 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/29 16:24:56 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	/* Iterator Tags */
		class input_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/InputIterator/ */
		class output_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/OutputIterator/ */
		class forward_iterator_tag : public input_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/ForwardIterator/ */
		class bidirectional_iterator_tag : public forward_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/BidirectionalIterator/ */
		class random_access_iterator_tag : public bidirectional_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */

	

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

			if (last - first < 0)
				return (0); // zorgt voor segfault als first after last is
			
			res = 0;
			while (first != last)
			{
				res++;
				first++;
			}
			return res;
		}


template <typename T>
struct is_iterator
{
	private:
		template <typename U>
		static int test(...);
		
		template <typename U>
		static char test(
					typename U::difference_type difference_type,
					typename U::value_type value_type,
					typename U::pointer pointer,
					typename U::iterator_category iterator_category
				);
	
	public:
		static bool const value = (sizeof(test<T>(0,0,0,0,0)) == sizeof(char));
};
	template <bool is_integral, typename T>
		struct is_integral_res {
			typedef T type;
			static const bool value = is_integral;
			};

	template <typename>
	struct is_integral_type : public is_integral_res<false, bool> { };
	template <>
	struct is_integral_type<bool> : public is_integral_res<true, bool> { };
	template <>
	struct is_integral_type<char> : public is_integral_res<true, char> { };
	template <>
	struct is_integral_type<signed char> : public is_integral_res<true, signed char> { };
	template <>
	struct is_integral_type<short int> : public is_integral_res<true, short int> { };
	template <>
	struct is_integral_type<int> : public is_integral_res<true, int> { };
	template <>
	struct is_integral_type<const int> : public is_integral_res<true, const int> { };
	template <>
	struct is_integral_type<long int> : public is_integral_res<true, long int> { };
	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> { };
	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> { };
	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> { };
	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <typename T>
	struct is_integral : public is_integral_type<T> { };


	template<bool Cond, class T = void>
	struct enable_if
	{

	};
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	 };










	/* https://github.dev/rchallie/ft_containers/tree/master/containers */
	/* https://www.cplusplus.com/reference/type_traits/is_integral/ */
}

#endif // UTILS_HPP
