#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
		std::deque<int> _dequeChain;
		std::vector<int> _vectorChain;
};

#endif