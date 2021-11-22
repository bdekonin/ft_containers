/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 12:36:57 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/22 11:30:18 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	/* Iterator Tags */
		class input_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/InputIterator/ */
		class output_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/OutputIterator/ */
		class forward_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/ForwardIterator/ */
		class bidirectional_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/BidirectionalIterator/ */
		class random_access_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */

	

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

			res = 0;
			while (first != last)
			{
				res++;
				first++;
			}
			return res;
		}






	/*
	** All the next part is an adaptation of is_integral.
	** "is_integral" for this project in C++98 is a structure 
	** that contain if the type given to it is a type from this list :
	**  - bool
	**  - char
	**  - char16_t
	**  - char32_t
	**  - wchar_t
	**  - signed char
	**  - short int
	**  - int
	**  - long int
	**  - long long int
	**  - unsigned char
	**  - unsigned short int
	**  - unsigned int
	**  - unsigned long int
	**  - unsigned long long int
	*/

	/*
	** @brief The basic struct of is_integral has
	** has a boolean ("value") that contain true if the type is from.
	** the list, otherwise false.
	*/
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
	struct is_integral_type<long int> : public is_integral_res<true, long int> { };
	template <>
	struct is_integral_type<long long int> : public is_integral_res<true, long long int> { };
	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> { };
	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> { };
	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> { };
	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};
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