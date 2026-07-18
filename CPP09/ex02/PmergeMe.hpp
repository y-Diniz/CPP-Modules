#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <cstdlib>
#include <deque>
#include <vector>

class PmergeMe {
	
	public:
		PmergeMe();
		PmergeMe( const std::vector<int> & );
		PmergeMe( const PmergeMe & );
		PmergeMe & operator=( const PmergeMe & );
		~PmergeMe();

		void processSort();

	private:
		std::deque<int> _deque;
		std::vector<int> _vector;
		size_t _size;

		std::vector< int > fordJohnson( const std::vector<int> & );
		std::deque< int > fordJohnson( const std::deque<int> & );
};

#endif