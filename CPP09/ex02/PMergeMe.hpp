#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <deque>
#include <vector>

class PMergeMe {
	
	public:
		PMergeMe();
		PMergeMe( const std::vector<int> & );
		PMergeMe( const PMergeMe & );
		PMergeMe & operator=( const PMergeMe & );
		~PMergeMe();

	private:
		std::deque<int> _deque;
		std::vector<int> _vector;

		std::vector< int > fordJohnson( const std::vector<int> & );
		std::deque< int > fordJohnson( const std::deque<int> & );
};

#endif