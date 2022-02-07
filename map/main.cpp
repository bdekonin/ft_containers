/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/02/07 12:15:10 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <sstream>

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

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(25);


		tree.printBT();
		std::cout << "height: " + std::to_string(tree.height(tree.root)) << std::endl;
		

		// std::cout << tree.leftbranch() << std::endl;
		// std::cout << tree.rightbranch() << std::endl;

		tree.reloop(tree.root);
	}
}