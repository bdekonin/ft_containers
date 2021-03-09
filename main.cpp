/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/09 14:10:31 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List/List.hpp"

#include <iostream> 
#include <list> 
#include <iterator>

#include "unistd.h"
#include "stdio.h"
#include <sys/stat.h> 
#include <fcntl.h>

// null
// one
// two
// three
// null

template<typename L, typename I>
void print(int fd, L list, I it, char *ptr)
{
	it = list.begin();
	
	// list.insert(it, 6, 5);

	int i = 0;

	std::cout << ptr << std::endl;
	std::cout << "head = " << *list.begin() << " | tail = " << *list.end() << "\n\n";
	for (I iterator = list.begin(); iterator != list.end(); iterator++)
	{
		std::cout << "(" << i << ")\t- [" << *iterator << "]\n";
		i++;
	}
	std::cout << "list.size() = " << *list.end() << "\n";
}

int main(void)
{
	std::list<int> gert (5, 42);
	std::list<int> list2 (4, 100);
	std::list<int>::iterator it2;
	list2.insert(list2.begin(), gert.begin(), gert.end());
	print(1, list2, it2, "OG");


	::List<int> kaas (5, 42);
	::List<int> list1 (4, 100);
	::List<int>::iterator it1;
	list1.insert(list1.begin(), kaas.begin(), kaas.end());
	print(1, list1, it1, "MY");
	// list1.print();
}

