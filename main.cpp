/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/18 14:29:33 by bdekonin      ########   odam.nl         */
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
	std::vector<int> og(5, 5);
	ft::vector<int> my(5, 5);
	printy(my, og);

	og.insert(og.begin(), 10, 9);
	my.insert(my.begin(), 10, 9);
	printy(my, og);

	og.insert(og.begin(), 6);
	my.insert(my.begin(), 6);
	printy(my, og);

	std::cout << ft::is_integral<std::string>::value;

	// my.insert(my.begin(), og.begin(), og.end());
	og.insert(og.begin(), 4, 2);
	my.insert(my.begin(), 4, 2);
	printy(my, og);

	// og.insert(og.begin(), 4, 2);
	// my.insert(my.begin(), 4, 2);
	// printy(my, og);

	// og.insert(og.begin(), 1, 8);
	// my.insert(my.begin(), 1, 8);
	// printy(my, og);

	// og.insert(og.begin(), 5, 7);
	// my.insert(my.begin(), 5, 7);
	// printy(my, og);

	// output: 000001999999999955555

	

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



