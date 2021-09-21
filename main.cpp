/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/21 14:37:31 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator/iterator.hpp"
#include "vector/vector.hpp"
#include "node/node.hpp"
#include "node/DoubleLinkedList.hpp"

int main(void)
{
    Vector<int> test;
    
    Vector<int>::iterator test1;


    Node<int> *node1 = new Node<int>(5);
    

    DoubleLinkedList<int> gert;
    
    gert.push_front(3);
    gert.push_front(1);
    gert.push_back(9);


    // list.push_back(new Node<int>(4));
    for (Node<int> *head = gert.getHead(); head; head = head->_next)
        std::cout << head->_content << std::endl;

    // delete node1;
}