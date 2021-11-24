/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/24 12:35:42 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "vector.hpp"
#include <vector>
# include <sstream>
#include <string>

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

#define PRINTERSIZE (int)vec.size()

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

	# define TEST_SUCCESS "[" GREEN "OK" RESET "] "
	# define TEST_FAILURE "[" RED	"KO" RESET "] "


	template < class T1, class T2 >
	void	print_difference(T1 expected, T2 received)
	{
		std::cout	<< "expected value: " << expected << std::endl\
					<< "received value: " << received << std::endl;
	}

template <class ft_vec, class std_vec>
bool	compare_these_vectors_yo(ft_vec& ft, std_vec& std)
{
	if (ft.size() != std.size()) {
		std::cout << "\nwrong size() :(" << std::endl;
		print_difference(std.size(), ft.size());
		return false;
	}
	if (ft.max_size() != std.max_size()) {
		std::cout << "\nwrong max_size() :(" << std::endl;
		print_difference(std.max_size(), ft.max_size());
		return false;
	}
	if (ft.empty() != std.empty()) {
		std::cout << "\nwrong empty() :(" << std::endl;
		print_difference(std.empty(), ft.empty());
		return false;
	}
	for(size_t i = 0; i < ft.size(); ++i) {
		if (ft[i] != std[i]) {
			std::cout << "\nindex: " << i << std::endl;
			print_difference(std[i], ft[i]);
			return false;
		}
	}
	return (true);
}

	template < class ft_val, class std_val >
		void	compare(ft_val& ft_con, std_val& std_con, bool(*comp)(ft_val&, std_val&), const char* test)
	{
		if (comp(ft_con, std_con) == true)
			std::cout << TEST_SUCCESS;
		else {
			std::cout << TEST_FAILURE;
			std::cout << "test: " << test << std::endl;
		}
	}

	template < class ft_val, class ft_itr, class std_val, class std_itr >
		void	compare(ft_val& ft_con, ft_itr ft_i, std_val& std_con, std_itr std_i, bool(*comp)(ft_val&, ft_itr, std_val&, std_itr), const char* test)
	{
		if (comp(ft_con, ft_i, std_con, std_i) == true)
			std::cout << TEST_SUCCESS;
		else {
			std::cout << TEST_FAILURE;
			std::cout << "test: " << test << std::endl;
		}
	}

/* Iterators: */
int main(void)
{
	{
		std::vector<int> vector;
		ft::vector<int> myvector;

		for (int i = 1; i <= 5; i++)
		{
			vector.push_back(i);
			myvector.push_back(i);
		}
		printy(myvector, vector);
	}
	{
		std::vector<int> vector (5);  // 5 default-constructed ints
		ft::vector<int> myvector (5);  // 5 default-constructed ints


		int i = 0;

		std::vector<int>::reverse_iterator rit = vector.rbegin();
		for (; rit!= vector.rend(); ++rit)
			*rit = ++i;

		i = 0;
		ft::vector<int>::reverse_iterator myrit = myvector.rbegin();
		for (; myrit!= myvector.rend(); ++myrit)
			*myrit = ++i;
		printy(myvector, vector);
	}
	{
		std::vector<int> ints;
		ft::vector<int> myints;

		for (int i=0; i<10; i++)
		{
			ints.push_back(i);
			myints.push_back(i);
		}
		printy(myints, ints);
		
		ints.insert (ints.end(),10,100);
		myints.insert (myints.end(),10,100);
		printy(myints, ints);

		ints.pop_back();
		myints.pop_back();
		printy(myints, ints);
	}
	{
		std::vector<int> vector;
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i = 0; i < 23; i++)
		{
			vector.push_back(i);
			myvector.push_back(i);
		}
		printy(myvector, vector);
	}
	{
		std::vector<int> vector;
		ft::vector<int> myvector;

		// set some initial content:
		for (int i = 1;i < 10;i++)
		{
			vector.push_back(i);
			myvector.push_back(i);
		}

		vector.resize(5);
		myvector.resize(5);
		printy(myvector, vector);

		vector.resize(8,100);
		myvector.resize(8,100);
		printy(myvector, vector);

		vector.resize(12);
		myvector.resize(12);
		printy(myvector, vector);
	}
	{
		std::vector<int> vector;
		ft::vector<int> myvector;
		int sum(0);

		for (int i=1;i<=10;i++)
		{
			vector.push_back(i);
			myvector.push_back(i);
		}

		while (!vector.empty())
		{
			sum += vector.back();
			vector.pop_back();
		}
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		printy(myvector, vector);
	}
	{
		std::vector<int> first, second, third;
		ft::vector<int> myfirst, mysecond, mythird;


		first.assign (7,100);             // 7 ints with a value of 100
		myfirst.assign (7,100);             // 7 ints with a value of 100

		std::vector<int>::iterator it;
		ft::vector<int>::iterator myit;
		it = first.begin() + 1;
		myit = myfirst.begin() + 1;
		printy(myfirst, first);
		
		second.assign (it, first.end() - 1); // the 5 central values of first
		mysecond.assign (myit, myfirst.end() - 1); // the 5 central values of first
		printy(mysecond, second);

		int myints[] = {1776, 7, 4};
		third.assign (myints, myints + 3);   // assigning from array.
		mythird.assign (myints, myints + 3);   // assigning from array.
		printy(mythird, third);
	}



	
	ft::vector<int> ft_dc;
	std::vector<int> std_dc;
	compare(ft_dc, std_dc, compare_these_vectors_yo, "Default constructor");

// /* set allocator */
	ft::vector<std::string, std::allocator<std::string> > ft_sa;
	std::vector<std::string, std::allocator<std::string> > std_sa;
	compare(ft_sa, std_sa, compare_these_vectors_yo, "Set allocator");

// /* fill constructor */
	ft::vector<int> ft_fc(42, 'a');
	std::vector<int> std_fc(42, 'a');
	compare(ft_dc, std_dc, compare_these_vectors_yo, "Fill constructor");

// /* range constructor */
	ft::vector<int> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
	std::vector<int> std_rc(std_fc.begin(), std_fc.end() - 21);
	compare(ft_rc, std_rc, compare_these_vectors_yo, "range constructor");

// /* copy constructor */
	ft::vector<int> ft_cc(ft_rc);
	std::vector<int> std_cc(std_rc);
	compare(ft_cc, std_cc, compare_these_vectors_yo, "Copy constructor");

	ft_rc.pop_back();
	std_rc.pop_back();
	compare(ft_rc, std_rc, compare_these_vectors_yo, "pop back()");
	compare(ft_cc, std_cc, compare_these_vectors_yo, "Deep copy (copy constructor)");

// /* assigantion operator */
	ft::vector<int> ft_ass = ft_cc;
	std::vector<int> std_ass = std_cc;
	compare(ft_ass, std_ass, compare_these_vectors_yo, "Assignation operator");

	ft_cc.erase(ft_cc.end() - 5);
	std_cc.erase(std_cc.end() - 5);
	compare(ft_cc, std_cc, compare_these_vectors_yo, "erase(pos)");
	compare(ft_ass, std_ass, compare_these_vectors_yo, "Deep copy (assignation operator)");
	


	ft::vector<std::string>				ft_vec(20, "MANY STRINGS YO");
	std::vector<std::string>			std_vec(20, "MANY STRINGS YO");
	ft::vector<std::string>				ft_empty;
	std::vector<std::string>			std_empty;

	system("leaks ft_containers");
	return (1);
}



