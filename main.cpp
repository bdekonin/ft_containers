/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/12 15:09:17 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator/iterator.hpp"
#include "vector/vector.hpp"
#include "node/node.hpp"
#include "node/DoubleLinkedList.hpp"
#include <vector>

template<typename T>
void printvec(T vec)
{
	std::vector<int>::iterator it = vec.begin();
	
	for (int i = 0; i < vec.capacity() ;i++, it++)
		std::cout << ' ' << *it;
	std::cout << "\t\t\t| " << vec.capacity() << " " << vec.size();
	std::cout  << std::endl;
}

template<typename T, typename K>
void printy(T my, K og)
{
	
	std::cout << "og: ";
	printvec(og);
	std::cout << "my: ";
	my.print(my.capacity());
	std::cout << "\n";
}

int main(void)
{
	// Vector<int> myvector(2, 2);
	// myvector.print(myvector.capacity());



	{
		Vector<int> myvector(2, 2);
		std::vector<int> ogvector(2, 2);
		printy(myvector, ogvector);
		

		ogvector.reserve(8);
		myvector.reserve(8);
		printy(myvector, ogvector);

		ogvector.resize(10);
		myvector.resize(10);
		printy(myvector, ogvector);
		



	}
}