/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/01 21:56:29 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

#include <iostream> 
#include <list> 
#include <iterator>


int main(void)
{
	::List<int>::iterator it;
	::List<int> list (4, 100);

	it = list.begin();
	it.print();
	it++;
	it.print();
}

// NULL == nullptr