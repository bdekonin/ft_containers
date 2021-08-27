/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 13:48:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/03/13 14:23:41 by bdekonin      ########   odam.nl         */
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

// tail
// head
// one
// two
// three
// tail
// head

template<typename L, typename I>
void print(L list, I it)
{
	it = list.begin();

	for (int i = 0; it != list.end(); i++)
	{
		std::cout << "(" << i + 1 << ")\t- " << "[" << *it << "]";
		if (it == list.begin())
			std::cout << " --> head";
		std::cout << "\n";
		it++;		
	}
	std::cout << "list.front() = [" << list.front() << "]"<< "\n";
	std::cout << "list.back()  = [" << list.back() << "]"<< "\n";
	std::cout << "list.size()  = [" << list.size() << "]"<< "\n";
	std::cout << "list.size()" << "\n";

}

void inserttesting()
{
	// std::cout << "---------------------------------------------\n\t\tString\n";
	// {	
	// 	std::list<std::string> list (5, "stringerd");
	// 	std::list<std::string>::iterator it;
	// 	list.insert(list.end(), 2, "kaas");
	// 	print(list, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<std::string> list (5, "stringerd");
	// 	::List<std::string>::iterator it;
	// 	list.insert(list.end(), 2, "kaas");
	// 	print(list, it);
	// }
	// std::cout << "---------------------------------------------\n";

	// std::cout << "---------------------------------------------\n\t\tDouble\n";
	// {
	// 	std::list<double> list (5, 42.6);
	// 	std::list<double>::iterator it;
	// 	list.insert(list.end(), 3, 69.420);
	// 	print(list, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<double> list (5, 42.6);
	// 	::List<double>::iterator it;
	// 	list.insert(list.end(), 3, 69.420);
	// 	print(list, it);
	// }
	// std::cout << "---------------------------------------------\n";

	// std::cout << "---------------------------------------------\n\t\tChar\n";
	// {
	// 	std::list<char> list (5, '+');
	// 	std::list<char>::iterator it;
	// 	print(list, it);
	// }
	// std::cout << std::endl;
	// {
	// 	::List<char> list (5, '+');
	// 	::List<char>::iterator it;
	// 	print(list, it);
	// }
	// std::cout << "---------------------------------------------\n";

	std::cout << "---------------------------------------------\n\t\tInteger\n";
	{
		std::list<int> list (5, 42);
		std::list<int>::iterator it;
		list.insert(list.begin(), 4, 8);
		list.clear();
		print(list, it);
	}
	std::cout << std::endl;
	{
		::List<int> list (5, 42);
		::List<int>::iterator it;
		list.insert(list.begin(), 4, 8);
		list.clear();
		print(list, it);
	}
	std::cout << "---------------------------------------------\n";
}

int main(void)
{
	inserttesting();	
}

