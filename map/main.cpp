/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/01/25 17:12:01 by bdekonin      ########   odam.nl         */
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


		
		tree.printBT();

		std::cout << "height: " + std::to_string(tree.height()) << std::endl;
	}
	tree <int>		tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	
	tree.printBT();

	std::cout << "height: " + std::to_string(tree.height()) << std::endl;






	// tree.print_tree();
}