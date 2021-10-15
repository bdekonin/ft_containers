/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/15 10:51:36 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator/iterator.hpp"
#include "vector/vector.hpp"
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
	my.print(my.size());
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

		ogvector.resize(6);
		myvector.resize(6);
		printy(myvector, ogvector);
	}


	Vector<int> myvector (1, 1);

	myvector.resize(2, 2);
	myvector.resize(3, 3);


	Vector<int>::iterator it = myvector.begin();

	if (myvector.begin() == myvector.begin())
		std::cout << "Same\n";
	else
		std::cout << "Different\n";


	if (myvector.begin() == myvector.end())
		std::cout << "Same\n";
	else
		std::cout << "Different\n";

		it->
	

}