/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:50:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 19:23:09 by bdekonin      ########   odam.nl         */
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

	while (tree.n != 2)
	{
		tree.remove(tree.n);
		tree.printBT();
	}

			tree.remove(1);
		tree.printBT();
					tree.remove(0);
		tree.printBT();
					tree.remove(2);
		tree.printBT();
	
	
	exit(4);
}