/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/08 11:25:24 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List/List.hpp"

#include <iostream> 
#include <list> 
#include <iterator>

// insertion

// null
// one
// two
// three
// null
void print()
{
	std::list<int> list1 (4, 100);
	std::list<int>::iterator og = list1.begin();

	::List<int> list2 (4, 100);
	::List<int>::iterator my = list2.begin();

		og++;
	my++;
		og++;
	my++;
		og++;
	my++;
		og++;
	my++;
	
		og++;
	// my++;
	std::list<int>::iterator ptr_og = og;
	::List<int>::iterator ptr_my = my;

	// list1.insert(og, 5, 1);
	// list2.insert(my, 5, 1);


	og = list1.begin();
	my = list2.begin();
	std::cout << "OG\t|     MY\n";
	int kaas = list1.size();
	for (int i = 0; i < list1.size(); i++)
	{
		if (ptr_og == og)
		{
			std::cout << "\033[1;31m";
			std::cout << *og;
			std::cout << "\033[0m";
		}
		else
			std::cout << *og;
		std::cout << "\t|     ";
		if (ptr_my == my)
		{
			std::cout << "\033[1;31m";
			std::cout << *my;
			std::cout << "\033[0m";
		}
		else
			std::cout << *my;
		std::cout << "\n";

		og++;
		my++;
	}	
}

int main(void)
{
	// print();
	
	::List<int> list (4, 100);
	::List<int>::iterator it = list.begin();

	it.print();

	
}
