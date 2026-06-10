#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {

	{
		std::vector<int> vector;
		
		vector.push_back(2);
		vector.push_back(23);
		vector.push_back(42);
		vector.push_back(7);

		std::vector<int>::iterator it = easyfind( vector, 42 );

		if (it != vector.end())
			std::cout << "Found: " << *it << std::endl;
		else
			std::cout << "Didn`t find" << std::endl;
	}

	{
		std::list<int> list;
		
		list.push_back(5);
		list.push_back(76);
		list.push_back(93);
		list.push_back(42);

		std::list<int>::iterator it = easyfind( list, 42 );

		if (it != list.end())
			std::cout << "Found: " << *it << std::endl;
		else
			std::cout << "Didn`t find" << std::endl;
	}

	{
		std::deque<int> deque;
		
		deque.push_back(9);
		deque.push_back(66);
		deque.push_back(24);
		deque.push_back(18);

		std::deque<int>::iterator it = easyfind( deque, 42 );

		if (it != deque.end())
			std::cout << "Found: " << *it << std::endl;
		else
			std::cout << "Didn`t find" << std::endl;
	}

	return 0;
}