/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/09 16:08:17 by bdekonin      ########   odam.nl         */
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

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <iostream>
# include <sstream>
# include <unistd.h>

// null
// one
// two
// three
// null

template<typename L, typename I>
void print(int size, L list, I it)
{
	it = list.begin();
	
	// list.insert(it, 6, 5);

	// int i = 0;

	// std::cout << "head = " << *list.begin() << " | tail = " << *list.end() << "\n";
	// for (I iterator = list.begin(); iterator != list.end(); iterator++)
	// {
	// 	std::cout << "(" << i << ")\t- [" << *iterator << "]\n";
	// 	i++;
	// }

	for (int i = 0; i < size; i++)
	{
		std::cout << "(" << i + 1 << ")\t- " << "[" << *it << "]";
		if (it == list.begin())
			std::cout << " --> HEAD";
		else if (it == list.end())
			std::cout << " --> TAIL";
		std::cout << "\n";
		it++;		
	}
	std::cout << "list.end() = " << *list.end() << "\n";
	std::cout << "list.size() = " << list.size() << "\n";
}

# define SIZE 10



template < class T, class Alloc = std::allocator<T> >
void test()
{
	const allocator_type &alloc = allocator_type();

	alloc.
}

int main(void)
{
	test();

	// std::cout << "---------------------------------------------\n\t\tString\n";
	// {	
	// 	std::list<std::string> gert (5, "stringerd");
	// 	std::list<std::string>::iterator it2;
	// 	print(1, gert, it2);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<std::string> jan (5, "stringerd");
	// 	::List<std::string>::iterator it1;
	// 	print(SIZE, jan, it1);
	// 	// list1.print();
	// }
	// std::cout << "---------------------------------------------\n";


	// std::cout << "---------------------------------------------\n\t\tInteger\n";
	// {
	// 	std::list<int> gert2 (5, 42);
	// 	std::list<int>::iterator it;
	// 	print(SIZE, gert2, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<int> jan2 (5, 42);
	// 	::List<int>::iterator it;
	// 	print(SIZE, jan2, it);
	// 	// jan2.print();
	// }
	// std::cout << "---------------------------------------------\n";
 

	// std::cout << "---------------------------------------------\n\t\tDouble\n";
	// {
	// 	std::list<double> gert2 (5, 42.6);
	// 	std::list<double>::iterator it;
	// 	print(SIZE, gert2, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<double> jan2 (5, 42.6);
	// 	::List<double>::iterator it;
	// 	print(SIZE, jan2, it);
	// 	// list1.print();
	// }
	// std::cout << "---------------------------------------------\n";

	
	// std::cout << "---------------------------------------------\n\t\tChar\n";
	// {
	// 	std::list<char> gert2 (5, '+');
	// 	std::list<char>::iterator it;
	// 	print(SIZE, gert2, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<char> jan2 (5, '+');
	// 	::List<char>::iterator it;
	// 	print(SIZE, jan2, it);
	// 	// list1.print();
	// }
	// std::cout << "---------------------------------------------\n";
}

