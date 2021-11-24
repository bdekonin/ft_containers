/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/24 10:43:46 by bdekonin      ########   odam.nl         */
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

#define PRINTERSIZE (int)vec.capacity()

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << " ]";
    return os;
}

void printog(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();

	for (int i = 0; i < PRINTERSIZE; i++, it++)
	{
		if (i >= (int)vec.size())
			std::cout << RED;
		std::cout << ' ' << *it << RESET;
	}
	std::cout << "\t\t\t| " << vec.capacity() << " " << vec.size();
	std::cout  << std::endl;
}
void printmy(ft::vector<int> &vec)
{
	ft::vector<int>::iterator it = vec.begin();

	for (int i = 0; i < PRINTERSIZE; i++, it++)
	{
		if (i >= (int)vec.size())
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

int main(void)
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

	og.insert(og.begin(), 4, 2);
	my.insert(my.begin(), 4, 2);

	og.push_back(8);
	my.push_back(8);

	og.clear();
	my.clear();
	printy(my, og);

	int myints[] = {1776,7,4};
	og.assign (myints,myints+3); // assigning from array
	my.assign (myints,myints+3); // assigning from array
	printy(my, og);
	
	og.assign (7,0);
	my.assign (7,0);
	printy(my, og);

	{
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7, 100); // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it = first.begin() + 1;

		second.assign (it,first.end() - 1); // the 5 central values of first

		int myints[] = {1776, 7, 4};
		third.assign (myints,myints + 3); // assigning from array.

		second.swap(third);

		std::cout << "Size of first: " << first.size() << " should be (7)\n";
		std::cout << "Size of second: " << second.size() << " should be (5)\n";
		std::cout << "Size of third: " << third.size() << " should be (3)\n";
	}

	og.insert(og.begin(), 1, 2);
	my.insert(my.begin(), 1, 2);
	og.insert(og.begin(), 1, 1);
	my.insert(my.begin(), 1, 1);
	printy(my, og);


	// og.erase (og.begin(), og.begin() + 2);
	// my.erase (my.begin(), my.begin() + 2);
	// printy(my, og);

	// og.erase (og.begin());
	// my.erase (my.begin());
	// printy(my, og);

	// og.clear();
	// my.clear();
	// printy(my, og);

{
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << " Should be  4 5 7 8 9 10\n";
}

	ft::vector<int> test1(my.begin(), my.begin() + 4);
	std::vector<int> test2(og.begin(), og.begin() + 4);
	ft::vector<int> test3(my);
	std::vector<int> test4(og);



	std::cout << "test1: " << test1 << std::endl;
	std::cout << "test2: " << test2 << std::endl;
	std::cout << "test3: " << test3 << std::endl;
	std::cout << "test4: " << test4 << std::endl;

	if (test1 == test1)
		std::cout << "test1 == test1\n";
	else
		std::cout << "test1 != test1\n";
	if (test1 == test3)
		std::cout << "test1 == test3\n\n";
	else
		std::cout << "test1 != test3\n\n";



	std::vector<int> v1;
	ft::vector<int> v2;

	v1.push_back(5);
	v2.push_back(5);

	v1.push_back(12);
	v2.push_back(12);

	v1.push_back(3);
	v2.push_back(3);

	printy(v2, v1);


	std::cout << "now testing insert without any allocating" << std::endl;
	{
		ft::vector<int> my1;
		std::vector<int> og1;
		
		my1.insert(my1.begin(), my.begin(), my.begin() + 4);
		og1.insert(og1.begin(), og.begin(), og.begin() + 4);
		printy(my1, og1);
	}

	{

		ft::vector<int> ft_dc;
		std::vector<int> std_dc;
		ft::vector<int> ft_fc(42, 'a');
		std::vector<int> std_fc(42, 'a');
	
		ft::vector<int> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
		std::vector<int> std_rc(std_fc.begin(), std_fc.end() - 21);
		printy(ft_rc, std_rc);
	}
{
	ft::vector<int> v1(0);
	v1.empty();
}
	return (1);
}



