/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/01/26 16:05:15 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"

int main()
{
	{
		tree <int>		tree;

		tree.insert(8);
		tree.insert(5);
		tree.insert(2);
		tree.insert(6);
		tree.insert(10);
		tree.insert(9);
		tree.insert(11);
		tree.insert(10);
		tree.insert(12);
		tree.insert(1);
		tree.insert(7);
		tree.recalculate(tree.root);
		
		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height()) << std::endl;
	}
	{
		tree <int>		tree;

		tree.insert(8);
		tree.insert(3);
		tree.insert(1);
		tree.insert(10);
		tree.insert(15);
		tree.insert(13);

		
		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height()) << std::endl;
	}

	exit(3);

	tree <int>		tree;

	std::string name;

	std::cout << "enter int" << std::endl;
	while(std::cin >> name)
	{
		std::cout << std::endl;
		tree.insert(stoi(name));
		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height()) << std::endl << std::endl;
		name = "";	
	}







	// tree.print_tree();
}