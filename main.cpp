/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/23 20:59:19 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator/iterator.hpp"
#include "vector/vector.hpp"
#include "node/node.hpp"
#include "node/DoubleLinkedList.hpp"
#include <vector>

int main(void)
{
	Vector<int> *kaas = new Vector<int>();

	// kaas->print(10);

	kaas->reserve(50);

	kaas->fill(25);

}