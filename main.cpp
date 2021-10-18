/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/18 16:01:46 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "vector.hpp"
#include <vector>

void printvec(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();
	
	for (int i = 0; i < vec.capacity(); i++, it++)
		std::cout << ' ' << *it;
	std::cout << "\t\t\t| " << vec.capacity() << " " << vec.size();
	std::cout  << std::endl;
}

void printy(ft::vector<int> &my, std::vector<int> &og)
{
	std::cout << "my: ";
	my.print();
	
	std::cout << "og: ";
	printvec(og);
	
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	// ft::vector<int> myvector(2, 2);
	// myvector.print(myvector.capacity());
	// {
	// 	ft::vector<int> myvector(2, 2);
	// 	std::vector<int> ogvector(2, 2);
	// 	printy(myvector, ogvector);
		

	// 	ogvector.reserve(8);
	// 	myvector.reserve(8);
	// 	printy(myvector, ogvector);

	// 	ogvector.resize(6);
	// 	myvector.resize(6);
	// 	printy(myvector, ogvector);
	// }


	// ft::vector<int> myvector (1, 1);

	// myvector.resize(2, 2);
	// myvector.resize(3, 3);


	// ft::vector<int>::iterator it = myvector.begin();

	// if (myvector.begin() == myvector.begin())
	// 	std::cout << "Same\n";
	// else
	// 	std::cout << "Different\n";


	// if (myvector.begin() == myvector.end())
	// 	std::cout << "Same\n";
	// else
	// 	std::cout << "Different\n";
	// std::cout << std::endl;


	// myvector.resize(4, 4);
	// myvector.resize(5, 5);

	// for (ft::vector<int>::iterator gert = myvector.begin(); gert != myvector.end(); gert++)
	// 	std::cout << *gert << " ";


	// std::cout << "\n";

	// ft::vector<int>::reverse_iterator keesjes = myvector.rbegin();


	// int i = 0;
	// for (ft::vector<int>::reverse_iterator gert = myvector.rbegin(); gert != myvector.rend(); gert++)
	// {
	// 	if ( i == 20)
	// 		break;
	// 	std::cout << *gert << " ";
	// 	i++;
	// }


	ft::vector<int> my(18, 5);
	std::vector<int> og(18, 5);

	// my.resize(19);
	// og.resize(19);
	printy(my, og);

	std::cout << og.capacity();
}



