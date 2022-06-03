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

// int main()
// {
// 	// create a map
// 	ft::map<int, char, std::greater<int> > myMap;

	

// 	// insert elements
// 	for (int letter = 'a', i = 0; i < 10; i++, letter++)
// 	{
// 		myMap._tree.insert(ft::make_pair(i, letter));
// 	}

// 	// ft::map<int, std::string>::iterator it = myMap.begin();
// 	myMap._tree.printBT();

// } 



void ftlong_operation()
{
	ft::map<int, char> myMap;

	

	// insert elements
	for (int letter = 'A', i = 0; i < 500000; i++, letter++)
	{
		myMap._tree.insert(ft::make_pair(i, letter));
		if (letter == 'z')
			letter = 'A';
	}

	// ft::map<int, std::string>::iterator it = myMap.begin();
	// myMap._tree.printBT();
	// myMap._tree.inorder();
}

void stdlong_operation()
{
	std::map<int, char> myMap;

	

	// insert elements
	for (int letter = 'A', i = 0; i < 500000; i++, letter++)
	{
		myMap.insert(std::make_pair(i, letter));
		if (letter == 'z')
			letter = 'A';
	}

	// ft::map<int, std::string>::iterator it = myMap.begin();
	// myMap._tree.printBT();
	// myMap._tree.inorder();
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    ftlong_operation();
	// stdlong_operation();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";
    return 0;
}

// ft
// 9ms
// 9.34675ms

// std
// 239ms
// 239.582ms