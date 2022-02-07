/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:25:26 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/11/28 19:30:01 by bdekonin      ########   odam.nl         */
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
#define STD_SIZE_TYPE typename std::vector<T>::size_type

#define FT_SIZE_TYPE typename ft::vector<T>::size_type


template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const FT_SIZE_TYPE size = vct.size();
	const FT_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "ft::size: " << size << std::endl;
	std::cout << "ft::capacity: " << isCapacityOk << std::endl;
	std::cout << "ft::max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "ft::content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	printSize(std::vector<T> const &vct, bool print_content = true)
{
	const STD_SIZE_TYPE size = vct.size();
	const STD_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "std::size: " << size << std::endl;
	std::cout << "std::capacity: " << isCapacityOk << std::endl;
	std::cout << "std::max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename std::vector<T>::const_iterator it = vct.begin();
		typename std::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "std::content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

	# define TEST_SUCCESS "[" GREEN "OK" RESET "] "
	# define TEST_FAILURE "[" RED	"KO" RESET "] "


	template < class T1, class T2 >
	void	print_difference(T1 expected, T2 received)
	{
		std::cout	<< "expected value: " << expected << std::endl\
					<< "received value: " << received << std::endl;
	}
	template <class ft_val, class std_val>
		bool	compare_these_values_yo(ft_val& ft, std_val& std)
	{
		if (ft != std) {
			print_difference(std, ft);
			return false;
		}
		return (true);
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
template < class ft_container, class std_container >
	void	push_back_increment(ft_container& ft_con, std_container& std_con, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.push_back(i);
		std_con.push_back(i);
	}
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

bool compare_exceptions(std::string& ft_exc, std::string& std_exc)
{
	if (ft_exc != std_exc) {
		print_difference(std_exc, ft_exc);
		return false;
	}
	else
		return true;
}
/* Iterators: */
int main(void)
{
	{
	// 	{
	// 		std::vector<int> vector;
	// 		ft::vector<int> myvector;

	// 		for (int i = 1; i <= 5; i++)
	// 		{
	// 			vector.push_back(i);
	// 			myvector.push_back(i);
	// 		}
	// 		printy(myvector, vector);
	// 	}
	// 	{
	// 		std::vector<int> vector (5);  // 5 default-constructed ints
	// 		ft::vector<int> myvector (5);  // 5 default-constructed ints


	// 		int i = 0;

	// 		std::vector<int>::reverse_iterator rit = vector.rbegin();
	// 		for (; rit!= vector.rend(); ++rit)
	// 			*rit = ++i;

	// 		i = 0;
	// 		ft::vector<int>::reverse_iterator myrit = myvector.rbegin();
	// 		for (; myrit!= myvector.rend(); ++myrit)
	// 			*myrit = ++i;
	// 		printy(myvector, vector);
	// 	}
	// 	{
	// 		std::vector<int> ints;
	// 		ft::vector<int> myints;

	// 		for (int i=0; i<10; i++)
	// 		{
	// 			ints.push_back(i);
	// 			myints.push_back(i);
	// 		}
	// 		printy(myints, ints);
			
	// 		ints.insert (ints.end(),10,100);
	// 		myints.insert (myints.end(),10,100);
	// 		printy(myints, ints);

	// 		ints.pop_back();
	// 		myints.pop_back();
	// 		printy(myints, ints);
	// 	}
	// 	{
	// 		std::vector<int> vector;
	// 		ft::vector<int> myvector;

	// 		// set some content in the vector:
	// 		for (int i = 0; i < 23; i++)
	// 		{
	// 			vector.push_back(i);
	// 			myvector.push_back(i);
	// 		}
	// 		printy(myvector, vector);
	// 	}
	// 	{
	// 		std::vector<int> vector;
	// 		ft::vector<int> myvector;

	// 		// set some initial content:
	// 		for (int i = 1;i < 10;i++)
	// 		{
	// 			vector.push_back(i);
	// 			myvector.push_back(i);
	// 		}

	// 		vector.resize(5);
	// 		myvector.resize(5);
	// 		printy(myvector, vector);

	// 		vector.resize(8,100);
	// 		myvector.resize(8,100);
	// 		printy(myvector, vector);

	// 		vector.resize(12);
	// 		myvector.resize(12);
	// 		printy(myvector, vector);
	// 	}
	// 	{
	// 		std::vector<int> vector;
	// 		ft::vector<int> myvector;
	// 		int sum(0);

	// 		for (int i=1;i<=10;i++)
	// 		{
	// 			vector.push_back(i);
	// 			myvector.push_back(i);
	// 		}

	// 		while (!vector.empty())
	// 		{
	// 			sum += vector.back();
	// 			vector.pop_back();
	// 		}
	// 		while (!myvector.empty())
	// 		{
	// 			sum += myvector.back();
	// 			myvector.pop_back();
	// 		}
	// 		printy(myvector, vector);
	// 	}
	// 	{
	// 		std::vector<int> first, second, third;
	// 		ft::vector<int> myfirst, mysecond, mythird;


	// 		first.assign (7,100);             // 7 ints with a value of 100
	// 		myfirst.assign (7,100);             // 7 ints with a value of 100

	// 		std::vector<int>::iterator it;
	// 		ft::vector<int>::iterator myit;
	// 		it = first.begin() + 1;
	// 		myit = myfirst.begin() + 1;
	// 		printy(myfirst, first);
			
	// 		second.assign (it, first.end() - 1); // the 5 central values of first
	// 		mysecond.assign (myit, myfirst.end() - 1); // the 5 central values of first
	// 		printy(mysecond, second);

	// 		int myints[] = {1776, 7, 4};
	// 		third.assign (myints, myints + 3);   // assigning from array.
	// 		mythird.assign (myints, myints + 3);   // assigning from array.
	// 		printy(mythird, third);
	// 	}



	// {	
	// 	ft::vector<int> ft_dc;
	// 	std::vector<int> std_dc;
	// 	compare(ft_dc, std_dc, compare_these_vectors_yo, "Default constructor");

	// // /* set allocator */
	// 	ft::vector<std::string, std::allocator<std::string> > ft_sa;
	// 	std::vector<std::string, std::allocator<std::string> > std_sa;
	// 	compare(ft_sa, std_sa, compare_these_vectors_yo, "Set allocator");

	// // /* fill constructor */
	// 	ft::vector<int> ft_fc(42, 'a');
	// 	std::vector<int> std_fc(42, 'a');
	// 	compare(ft_dc, std_dc, compare_these_vectors_yo, "Fill constructor");

	// // /* range constructor */
	// 	ft::vector<int> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
	// 	std::vector<int> std_rc(std_fc.begin(), std_fc.end() - 21);
	// 	compare(ft_rc, std_rc, compare_these_vectors_yo, "range constructor");

	// // /* copy constructor */
	// 	ft::vector<int> ft_cc(ft_rc);
	// 	std::vector<int> std_cc(std_rc);
	// 	compare(ft_cc, std_cc, compare_these_vectors_yo, "Copy constructor");

	// 	ft_rc.pop_back();
	// 	std_rc.pop_back();
	// 	compare(ft_rc, std_rc, compare_these_vectors_yo, "pop back()");
	// 	compare(ft_cc, std_cc, compare_these_vectors_yo, "Deep copy (copy constructor)");

	// // /* assigantion operator */
	// 	ft::vector<int> ft_ass = ft_cc;
	// 	std::vector<int> std_ass = std_cc;
	// 	compare(ft_ass, std_ass, compare_these_vectors_yo, "Assignation operator");

	// 	ft_cc.erase(ft_cc.end() - 5);
	// 	std_cc.erase(std_cc.end() - 5);
	// 	compare(ft_cc, std_cc, compare_these_vectors_yo, "erase(pos)");
	// 	compare(ft_ass, std_ass, compare_these_vectors_yo, "Deep copy (assignation operator)");
	}


{
		ft::vector<std::string>				ft_vec(2000, "MANY STRINGS YO");
		std::vector<std::string>			std_vec(2000, "MANY STRINGS YO");
		ft::vector<std::string>				ft_empty;
		std::vector<std::string>			std_empty;

	/* iterator range assign */
		ft_empty.assign(ft_vec.begin() + 42, ft_vec.begin() + 1337);
		std_empty.assign(std_vec.begin() + 42, std_vec.begin() + 1337);
		compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(std_vec.begin() + 42, std_vec.begin + 1337)");

	/* fill assign */
		std::string assigned("we just got assigned yo");
		ft_empty.assign(420, assigned);
		std_empty.assign(420, assigned);
		compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(420, assigned)");

		ft_empty.assign(5000, std::string("wejoooowww"));
		std_empty.assign(5000, std::string("wejoooowww"));
		compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(5000, \"wejoow\")");
		
	/* push back */
		for (size_t i = 0; i < 6969; ++i) {
			ft_empty.push_back(std::to_string(i));
			std_empty.push_back(std::to_string(i));
		}
		compare(ft_empty, std_empty, compare_these_vectors_yo, "push back increment");

	/* pop back */
		for (size_t i = 0; i < 6969; i++) {
			ft_empty.pop_back();
			std_empty.pop_back();
		}
		compare(ft_empty, std_empty, compare_these_vectors_yo, "pop_back() * 6969");

	/* insert */
		ft_empty.insert(ft_empty.begin() + 42, "LEGENDARY");
		std_empty.insert(std_empty.begin() + 42, "LEGENDARY");
		compare(ft_empty, std_empty, compare_these_vectors_yo, "insert(begin() + 42, \"LEGENDARY\")");

	/* range erase */
		ft_empty.erase(ft_empty.begin(), ft_empty.end() - 1);
		std_empty.erase(std_empty.begin(), std_empty.end() - 1);
		compare(ft_empty, std_empty, compare_these_vectors_yo, "begin(), end() - 1");

	/* fill insert */
		ft_empty.insert(ft_empty.end() - 1, 1337, "living on the edge");
		std_empty.insert(std_empty.end() - 1, 1337, "living on the edge");
		compare(ft_empty, std_empty, compare_these_vectors_yo, "end() - 1, 1337, \"living on the edge");

	/* element erase */
		for (size_t i = 0; i < ft_empty.size(); i++) {
			ft_empty.erase(ft_empty.begin() + i);
			std_empty.erase(std_empty.begin() + i);

		}
		compare(ft_empty, std_empty, compare_these_vectors_yo, "erase(begin() + i)");

	/* Range insert */
		ft_empty.insert(ft_empty.begin(), ft_vec.begin(), ft_vec.end());
		std_empty.insert(std_empty.begin(), std_vec.begin(), std_vec.end());
		compare(ft_empty, std_empty, compare_these_vectors_yo, "empty.begin(), vec.begin(), vec.end()");

	/* clear test */
		ft_empty.clear();
		std_empty.clear();
		compare(ft_empty, std_empty, compare_these_vectors_yo, "clear()");

	/* swaperoo */
		ft_empty.insert(ft_empty.begin(), 42, "About to get swapped");
		std_empty.insert(std_empty.begin(), 42, "About to get swapped");
		ft_empty.swap(ft_vec);
		std_empty.swap(std_vec);
		compare(ft_empty, std_empty, compare_these_vectors_yo, "swap()");
		compare(ft_vec, std_vec, compare_these_vectors_yo, "swap()");
}
{
	ft::vector<size_t> ft_vec;
	std::vector<size_t> std_vec;

	push_back_increment(ft_vec, std_vec, 1337);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "[] operator");

/* subscript operator */
	int j = ft_vec.size() - 1;
	for (int i = 0; i != j; i++) {
		ft_vec[j] = std_vec[i];
		std_vec[j] = std_vec[i];
	}
	compare(ft_vec, std_vec, compare_these_vectors_yo, "reversed with [] operator");

/* at */
	std::string ft_msg;
	std::string std_msg;
	try {
		for (size_t i = 0; i < ft_vec.size() + 1; i++)
			if (ft_vec.at(i) != std_vec.at(i))
				break ;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		for (size_t i = 0; i < std_vec.size() + 1; i++)
			std_vec.at(i);
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(ft_vec.size() + 1)");

	try {
		std::cout << ft_vec.at(-1) << std::endl;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		std::cout << std_vec.at(-1) << std::endl;
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(-1");
	/* front && back */


	std::vector<int> vct(5);
	ft::vector<int> ftvct(5);

	std::vector<int> vct2;
	ft::vector<int> ftvct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	for (unsigned long int i = 0; i < ftvct.size(); ++i)
		ftvct[i] = (ftvct.size() - i) * 7;
	printSize(vct, false);
	printSize(ftvct, false);


	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	ftvct2.insert(ftvct2.begin(), ftvct.begin(), ftvct.begin() + cut);
	printSize(vct2, false);
	printSize(ftvct2, false);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	ftvct2.insert(ftvct2.begin(), ftvct.begin() + cut, ftvct.end());
	printSize(vct2, false);
	printSize(ftvct2, false);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	ftvct2.insert(ftvct2.end(), ftvct.begin(), ftvct.begin() + cut);
	printSize(vct2, false);
	printSize(ftvct2, false);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *ftvct2.insert(ftvct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << *ftvct2.insert(ftvct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	


	
	// compare(ft_vec.front(), std_vec.front(), compare_these_values_yo, "front()");
	// compare(ft_vec.back(), std_vec.back(), compare_these_values_yo, "back()");

	std::cout << "back: " << std_vec.back() << " | backmy: " << ft_vec.back() << std::endl;
}


	std::cout << "press a key please\n";
	std::cin.ignore();
	return (1);
}
