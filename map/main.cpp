/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/02/07 15:18:44 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <sstream>
#include <map>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

int main()
{
	{
		tree <int>		tree;

		// tree.insert(33);
		// tree.insert(9);
		// tree.insert(53);
		// tree.insert(61);
		// tree.insert(8);
		// tree.insert(21);
		// tree.insert(11);
		// tree.insert(80);

	// tree.root = tree.insert(tree.root, 42);
	// tree.root = tree.insert(tree.root, 35);
	// tree.root = tree.insert(tree.root, 19);
	// tree.root = tree.insert(tree.root, 31);
	// tree.root = tree.insert(tree.root, 14);
	// tree.root = tree.insert(tree.root, 25);
	// tree.root = tree.insert(tree.root, 27);
	// tree.root = tree.insert(tree.root, 10);

	tree.root = tree.insert(tree.root, 1);
	tree.root = tree.insert(tree.root, 2);
	tree.root = tree.insert(tree.root, 3);
	tree.root = tree.insert(tree.root, 4);
	tree.root = tree.insert(tree.root, 6);
	tree.root = tree.insert(tree.root, 4);

	// print getnext
	std::cout << "getnext: ";
	std::cout << tree.getnext()->data << std::endl << std::endl;
	
		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height(tree.root)) << std::endl;
	}
	exit(4);
	

























	
	// {
	// 	std::map<int, std::string>		tree;

	// 	tree.insert(std::pair<int, std::string>(1, "one"));
	// 	tree.insert(std::pair<int, std::string>(2, "two"));
	// 	tree.insert(std::pair<int, std::string>(3, "three"));
	// 	tree.insert(std::pair<int, std::string>(4, "four"));
	// 	tree.insert(std::pair<int, std::string>(5, "five"));

	// 	std::map<int, std::string>::iterator	it;
	// 	it = tree.begin();

	// 	while (it != tree.end())
	// 	{
	// 		std::cout << it->first << ": " << it->second << std::endl;
	// 		it++;
	// 	}
	// }

	// std::cout << std::endl << std::endl;
	
	// {
	// 	std::map<std::string, int>		tree;

	// 	tree.insert(std::pair<std::string, int>("one", 1));
	// 	tree.insert(std::pair<std::string, int>("two", 2));
	// 	tree.insert(std::pair<std::string, int>("three", 3));
	// 	tree.insert(std::pair<std::string, int>("four", 4));
	// 	tree.insert(std::pair<std::string, int>("five", 5));

	// 	std::map<std::string, int>::iterator	it;
	// 	it = tree.begin();

	// 	while (it != tree.end())
	// 	{
	// 		std::cout << it->first << ": " << it->second << std::endl;
	// 		it++;
	// 	}
	// }
	
	// std::cout << std::endl << std::endl;

	// {
	// 	std::string strings[] = { "one", "two", "three", "four", "five" };
	// 	std::vector<std::string>		tree(strings, strings + sizeof(strings) / sizeof(strings[0]));

	// 	// print all elements of the vector tree
	// 	for (std::vector<std::string>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 		std::cout << *it << ' ';
	// 	std::cout << std::endl;

	// 	std::sort(tree.begin(), tree.end());

	// 	// print all elements of the vector tree
	// 	for (std::vector<std::string>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 		std::cout << *it << ' ';
		
		
	// }
}