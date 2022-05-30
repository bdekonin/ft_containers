/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 20:59:52 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "tree.hpp"
#include <sstream>
#include <map>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

#include "utils.hpp"

int main()
{
	AVL<int> tree;

	for (int i = 0; i < 10; i++)
	{
		tree.insert(i);
	}
	tree.printBT();
/*
├──3 (0) 
│   ├──1 (3) 
│   │   ├──0 (1) 
│   │   └──2 (1) 
│   └──7 (3) 
│       ├──5 (7) 
│       │   ├──4 (5) 
│       │   └──6 (5) 
│       └──8 (7) 
│           └──9 (8) 
*/
/*
├──3 (0) 
│   ├──7 (3) 
│   │   ├──8 (7) 
│   │   │   ├──9 (8) 
│   │   └──5 (7) 
│   │       ├──6 (5) 
│   │       └──4 (5) 
│   └──1 (3) 
│       ├──2 (1) 
│       └──0 (1)
*/
	
	
	exit(4);
}