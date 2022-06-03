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

#include "AVL.hpp"
#include "pair.hpp"

int main()
{
	ft::pair<char, int> pair1('a', 2);

	AVL<ft::pair<char, int> > tree;

	for (int l = 'a', i = 0; i < 15; l++, i++)
	{
		tree.insert(ft::pair<char, int>(l, i));
	}

	AVL<int>::node

	tree.printBT();
	tree.inorder();
	
	exit(4);
}