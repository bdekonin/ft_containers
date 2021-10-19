/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/10/19 21:58:59 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "vector.hpp"
#include <vector>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


void printog(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();

	for (int i = 0; i < vec.capacity(); i++, it++)
	{
		if (i >= vec.size())
			std::cout << RED;
		std::cout << ' ' << *it << RESET;
	}
	std::cout << "\t\t\t| " << vec.capacity() << " " << vec.size();
	std::cout  << std::endl;
}
void printmy(ft::vector<int> &vec)
{
	ft::vector<int>::iterator it = vec.begin();

	for (int i = 0; i < vec.capacity(); i++, it++)
	{
		if (i >= vec.size())
			std::cout << RED;
		std::cout << ' ' << *it << RESET;
	}
	std::cout << "\t\t\t| " << vec.capacity() << " " << vec.size();
	std::cout  << std::endl;
}

void printy(ft::vector<int> &my, std::vector<int> &og)
{
	std::cout << "my: ";
	printmy(my);
	
	std::cout << "og: ";
	printog(og);
	
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


	ft::vector<int> my(5, 5);
	std::vector<int> og(5, 5);
	printy(my, og);

	og.insert(og.begin(), 6, 1);
	my.insert(my.begin(), 6, 1);
	printy(my, og);

	// og.insert(og.begin(), 4, 2);
	// my.insert(my.begin(), 4, 2);
	// printy(my, og);

	// og.insert(og.begin(), 4, 2);
	// my.insert(my.begin(), 4, 2);
	// printy(my, og);

	// og.insert(og.begin(), 1, 8);
	// my.insert(my.begin(), 1, 8);
	// printy(my, og);

	// og.insert(og.begin(), 5, 7);
	// my.insert(my.begin(), 5, 7);
	// printy(my, og);

	

	// my.resize(16, 3);
	// og.resize(16, 3);
	// printy(my, og);

	// my.resize(6);
	// og.resize(6);
	// printy(my, og);
	
	// my.resize(10, 9);
	// og.resize(10, 9);
	// printy(my, og);

	// my.resize(20, 1);
	// og.resize(20, 1);
	// printy(my, og);

	// my.resize(33);
	// og.resize(33);
	// printy(my, og);
	
	return (1);
}



