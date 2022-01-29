/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/01/29 13:47:33 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <sstream>

int main()
{
	{
		tree <int>		tree;

		tree.insert(10);
		tree.insert(8);
		tree.insert(15);
		tree.insert(13);
		tree.insert(4);
		tree.insert(2);
		tree.insert(1);
		tree.insert(0);
		tree.insert(12);
		tree.insert(54);
		tree.insert(72);
		tree.insert(67);


		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height(tree.root)) << std::endl;
		std::cout << "depth: " + std::to_string(tree.deepestNode(tree.root)->data) << std::endl;
		std::cout << "left: " + std::to_string(tree.deepestNode(tree.root->left)->data) << std::endl;
		std::cout << "right: " + std::to_string(tree.deepestNode(tree.root->right)->data) << std::endl;
		std::cout << "balance factor: " << tree.getBalancedFactor() << std::endl << std::endl;
		

		// std::cout << tree.leftbranch() << std::endl;
		// std::cout << tree.rightbranch() << std::endl;
	}
	exit(3);



	tree<int> tree;
	std::string name;

	// get name from user in while loop
	// if name is "quit" then break
	// else insert name into tree
	while (1)
	{
		std::cout << "Enter name: ";
		std::cin >> name;
		if (name == "quit")
			break;
		tree.insert(stoi(name));
		tree.printBT();
		if (tree.height(tree.root) > 3)
		{
			std::cout << "height: " + std::to_string(tree.height(tree.root)) << std::endl;
			std::cout << "depth: " + std::to_string(tree.deepestNode(tree.root)->data) << std::endl;
			// std::cout << "left: " + std::to_string(tree.deepestNode(tree.root->left)->data) << std::endl;
			// std::cout << "right: " + std::to_string(tree.deepestNode(tree.root->right)->data) << std::endl;
			std::cout << "balance factor: " << tree.getBalancedFactor() << std::endl << std::endl;
		}
		std::cout << std::endl;
	}
}