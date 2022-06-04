/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 20:31:19 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "tree.hpp"
#include <sstream>
#include <map>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "pair.hpp"
#include "map.hpp"
#include "AVL.hpp"

#include <chrono>

/* Only needed for the sake of this example. */
#include <iostream>
#include <thread>

# define MAXSIZE 50000
// int main()
// {
// 	ft::map<int, std::string> myMap;

	
// 	std::string s = "Hallo ik ben bob";

// 	int max = 1;
// 	for (int i = 0; i < max; i++)
// 	{
// 		myMap._tree.insert(ft::make_pair(i, s));
// 	}

// 	for (int i = 0; i < max; i++)
// 	{
// 		myMap._tree.search(i);
// 	}

// 	std::cout << "Size: " << myMap._tree.size() << std::endl;
// } 




void ftlong_operation()
{
	ft::map<int, std::string> myMap;

	
	std::string s = "Hallo ik ben bob";

	int max = MAXSIZE;
	// insert elements
	for (int i = 0; i < max; i++)
	{
		myMap._tree.insert(ft::make_pair(i, s));
	}

	std::cout << "ft: Size: " << myMap._tree.size() << std::endl;

	for (int i = 0; i < max; i++)
	{
		myMap._tree.search(i);
	}

	for (int i = max; i > 0; i--)
	{
		myMap._tree.remove(i);
	}

	std::cout << "ft: Size: " << myMap._tree.size() << std::endl;
}

void stdlong_operation()
{
	std::map<int, std::string> myMap;

	
	std::string s = "Hallo ik ben bob";

	int max = MAXSIZE;
	// insert elements
	for (int i = 0; i < max; i++)
	{
		myMap.insert(std::make_pair(i, s));
	}

	std::cout << "std: Size: " << myMap.size() << std::endl;
	
	for (int i = 0; i < max; i++)
	{
		myMap.find(i);
	}

	for (int i = max; i > 0; i--)
	{
		myMap.erase(i);
	}

	// ft::map<int, std::string>::iterator it = myMap.begin();
	// myMap._tree.printBT();
	// myMap._tree.inorder();

	std::cout << "std: Size: " << myMap.size() << std::endl;
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

	{
		auto t1 = high_resolution_clock::now();
		stdlong_operation();
		// stdlong_operation();
		auto t2 = high_resolution_clock::now();

		/* Getting number of milliseconds as an integer. */
		auto ms_int = duration_cast<milliseconds>(t2 - t1);

		/* Getting number of milliseconds as a double. */
		duration<double, std::milli> ms_double = t2 - t1;

		std::cout << "std: " << ms_int.count() << "ms\n";
		std::cout << "std: " << ms_double.count() << "ms\n";
	}
	std::cout << std::endl << std::endl;
	{
		auto t1 = high_resolution_clock::now();
		ftlong_operation();
		// stdlong_operation();
		auto t2 = high_resolution_clock::now();

		/* Getting number of milliseconds as an integer. */
		auto ms_int = duration_cast<milliseconds>(t2 - t1);

		/* Getting number of milliseconds as a double. */
		duration<double, std::milli> ms_double = t2 - t1;

		std::cout << "ft: " << ms_int.count() << "ms\n";
		std::cout << "ft: " << ms_double.count() << "ms\n";
	}
    return 0;
}

// std: 393ms
// std: 393.804ms
// ft: 236ms
// ft: 236.85ms