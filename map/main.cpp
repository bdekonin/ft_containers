/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/28 13:33:54 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "tree.hpp"
#include <sstream>
#include <map>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "pair.hpp"
#include "map.hpp"
#include "utils.hpp"

int main()
{
	AVL<int> tree;

	for (int i = 0; i < 11; i++)
	{
		tree.insert(i);
	}
	tree.printBT();
	tree.remove(3); 

	tree.printBT();

	
	tree.inorder();

	exit(4);


	
	// avltree<int> tree;

	// for (int i = 0; i < 11; i++)
	// {
	// 	tree.insert(i);
	// 	// tree.printBT();
	// 	// getchar();
	// 	// system("clear");
	// }
	// tree.printBT();
	// tree.deleteNode(9);
	// tree.printBT();
	// // tree.deleteNode(7);
	// // tree.printBT();

	

	// exit(3);
	// {
	// 	ft::pair<char, int> p1('a', 10);
	// 	ft::pair<char, int> p2('b', 20);
	// 	ft::pair<char, int> p3('c', 30);
	// 	ft::pair<char, int> p4('d', 40);
		

	// 	std::cout << p1.first << "-" << p1.second << std::endl;
	// 	std::cout << p2.first << "-" << p2.second << std::endl;
	// 	std::cout << p3.first << "-" << p3.second << std::endl;
	// 	std::cout << p4.first << "-" << p4.second << std::endl;

	// 	ft::map<char, int> test;
	// 	exit(4);
	// 	tree <int>		tree;
	// 	for (int i = 1; i < 30; i++)
	// 	{
	// 		std::cout << "Adding: " << i << std::endl;
	// 		tree.root = tree.insert(tree.root, i);
	// 		tree.printBT();
	// 		std::cout << "height: " + std::to_string(tree.height(tree.root)) << std::endl;
	// 		getchar();
	// 		system("clear");
	// 	}
	// }
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