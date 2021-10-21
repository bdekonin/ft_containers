/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 12:36:57 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/21 16:39:14 by bdekonin      ########   odam.nl         */
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

	





	/* https://github.dev/rchallie/ft_containers/tree/master/containers */
	/* https://www.cplusplus.com/reference/type_traits/is_integral/ */
}

#endif // UTILS_HPP