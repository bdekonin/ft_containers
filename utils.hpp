/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 12:36:57 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/21 13:09:38 by bdekonin      ########   odam.nl         */
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
    ** @brief The basic struct of is_integral has
    ** has a boolean ("value") that contain true if the type is from.
    ** the list, otherwise false.
    */
    template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    /*
    ** @brief default template of the structure is_integral_type.
    ** If the type given in argument is from the list, the structure
    ** will be overide by nexts, in according to it type.
    ** If the type given is argument isn't in the list, 
    ** stocked value will be false. So it's not a integral type.
    */
    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    /* @brief is_integral_type for bool. "value is true".*/
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};


	/* https://www.cplusplus.com/reference/type_traits/is_integral/ */
}

#endif // UTILS_HPP