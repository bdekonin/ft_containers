/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/04 18:47:45 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

#include <iostream> 
#include <list> 
#include <iterator>

::List<int>		list1 (3, 100);
std::list<int>	list3 (3, 100);

::List<int>::iterator it1 = list1.begin();
std::list<int>::iterator it3 = list3.begin();

void print()
{
	::List<int>::iterator it2 = list1.begin();
	std::list<int>::iterator it6 = list3.begin();

	it2++;
	it6++;
	it2++;
	it6++;
	it2++;
	it6++;
	it2++;
	it6++;

	*it2 = 21;
		*it6 = 21;

	std::cout << "--> "<< *it2 << " " << *it6 << "\n";
	

	// list1.insert(it2, 3, 20);
	// list3.insert(it6, 3, 20);

	it1 = list1.begin();
	it3 = list3.begin();
	while (it3 != list3.end())
	{
		std::cout << *it1 << " " << *it3 << "\n";

		it1++;
		it3++;
	}
	
}

int main(void)
{
	print();
}
