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

# define MAXSIZE 500
# define STRING "Hi"

int main()
{
	ft::map<int, int> mymap;

	for (int i = 0; i < 10; i++)
	{
		mymap._tree.insert(ft::make_pair(1, i));
	}
	// // iterate through mymap
	// for (auto it = mymap.begin(); it != mymap.end(); ++it)
	// {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }

	mymap._tree.printBT();
	ft::map<int, int>::iterator it = mymap.begin();

		std::cout << it->key << std::endl;

		it.nextNode();
	
	// std::cout << it->first << " => " << it->second << '\n';

} 




// void ftlong_operation()
// {
// 	ft::map<int, float> myMap;
// 	int max = MAXSIZE;

// 	std::cout << "ft: adding " << max << " elements" << std::endl;

// 	for (int i = 0; i < max; i++)
// 		myMap._tree.insert(ft::make_pair(i, i * 2 / 3.14));
// 	std::cout << "ft: Size: " << myMap._tree.size() << std::endl;

// 	for (int i = 0; i < max; i++)
// 		myMap._tree.search(i);

// 	std::cout << "ft: Removing " << myMap._tree.size() << " elements" << std::endl;

// 	for (int i = max; i >= 0; i--)
// 		myMap._tree.remove(i);
// 	std::cout << "ft: Size: " << myMap._tree.size() << std::endl;
// }

// void stdlong_operation()
// {
// 	std::map<int, float> myMap;
// 	int max = MAXSIZE;

// 	std::cout << "std: adding " << max << " elements" << std::endl;

// 	for (int i = 0; i < max; i++)
// 		myMap.insert(std::make_pair(i, i * 2 / 3.14));
// 	std::cout << "std: Size: " << myMap.size() << std::endl;

// 	for (int i = 0; i < max; i++)
// 		myMap.find(i);

// 	std::cout << "std: Removing " << myMap.size() << " elements" << std::endl;

// 	for (int i = max; i >= 0; i--)
// 		myMap.erase(i);
// 	std::cout << "std: Size: " << myMap.size() << std::endl;
// }

// int main()
// {
//     using std::chrono::high_resolution_clock;
//     using std::chrono::duration_cast;
//     using std::chrono::duration;
//     using std::chrono::milliseconds;

// 	{
// 		auto t1 = high_resolution_clock::now();
// 		stdlong_operation();
// 		// stdlong_operation();
// 		auto t2 = high_resolution_clock::now();

// 		/* Getting number of milliseconds as an integer. */
// 		auto ms_int = duration_cast<milliseconds>(t2 - t1);

// 		/* Getting number of milliseconds as a double. */
// 		duration<double, std::milli> ms_double = t2 - t1;

// 		std::cout << "std: " << ms_int.count() << "ms\n";
// 		std::cout << "std: " << ms_double.count() << "ms\n";
// 	}
// 	std::cout << std::endl << std::endl;
// 	{
// 		auto t1 = high_resolution_clock::now();
// 		ftlong_operation();
// 		// stdlong_operation();
// 		auto t2 = high_resolution_clock::now();

// 		/* Getting number of milliseconds as an integer. */
// 		auto ms_int = duration_cast<milliseconds>(t2 - t1);

// 		/* Getting number of milliseconds as a double. */
// 		duration<double, std::milli> ms_double = t2 - t1;

// 		std::cout << "ft: " << ms_int.count() << "ms\n";
// 		std::cout << "ft: " << ms_double.count() << "ms\n";
// 	}
//     return 0;
// }

// std: 393ms
// std: 393.804ms
// ft: 236ms
// ft: 236.85ms