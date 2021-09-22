/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/22 15:49:45 by bdekonin      ########   odam.nl         */
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
    Vector<int>::iterator test2;
    
    if (test1 != test2)
        test.add(5);
    
    test.print();
    return 1;


    Node<int> *node1 = new Node<int>(9);
    

    DoubleLinkedList<int> gert;
    
    gert.push_front(3);
    gert.push_front(1);
    gert.push_front(node1);
    gert.push_front(-1);
    gert.push_front(500);

    gert.insert(new Node<int>(18), node1);

    for (Node<int> *head = gert.begin(); head; head = head->_next)
        std::cout << head->_content << std::endl;

    std::cout << "\t\t" << gert[2]->_content << std::endl;


    for (Node<int> *head = gert.begin(); head; head = head->_next)
        std::cout << head->_content << std::endl;
}