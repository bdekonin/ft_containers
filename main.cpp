/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/24 11:31:04 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator/iterator.hpp"
#include "vector/vector.hpp"
#include "node/node.hpp"
#include "node/DoubleLinkedList.hpp"
#include <vector>

int main(void)
{

	{
		std::cout << "std::vector:\t";
		std::vector<int> myvector;
		for (int i = 1; i < 10; i++)
			myvector.push_back(i);		
		myvector.resize(3);
		myvector.resize(8);
		// myvector.resize(12);
		std::cout << "cap: (" << myvector.capacity() << ")\t:";
		std::cout << "size: (" << myvector.size() << ")\t:";
		for (int i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{
		std::cout << "My::Vector:\t";
		Vector<int> myvector;
		
		for (int i = 1; i < 10; i++)
			myvector.push_back(i);

			std::cout << "cap: (" << myvector.capacity() << ")\t:";
			std::cout << "size: (" << myvector.size() << ")\t:";
			myvector.print(myvector.size());

		myvector.resize(3);
			std::cout << "cap: (" << myvector.capacity() << ")\t:";
			std::cout << "size: (" << myvector.size() << ")\t:";
			myvector.print(myvector.size());
		
		myvector.resize(8);
			std::cout << "cap: (" << myvector.capacity() << ")\t:";
			std::cout << "size: (" << myvector.size() << ")\t:";
			myvector.print(myvector.size());
		
		// myvector.resize(12);
			std::cout << "cap: (" << myvector.capacity() << ")\t:";
			std::cout << "size: (" << myvector.size() << ")\t:";
			myvector.print(myvector.size());
		
		std::cout << "cap: (" << myvector.capacity() << ")\t:";
		std::cout << "size: (" << myvector.size() << ")\t:";
		myvector.print(myvector.size());
		std::cout << "\n";
	}

	


	// myvector.print(myvector.size());
	// std::cout << "\n\n";
	
	// myvector.print(myvector.size());
	// std::cout << "\n\n";
	
	// myvector.print(myvector.size() + 1);
	// std::cout << "\n\n";
	// std::cout << myvector.size() << std::endl;
	// std::cout << myvector.capacity() << std::endl;

}