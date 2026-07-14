#include "PMergeMe.hpp"
#include <utility>

PMergeMe::PMergeMe() { }

PMergeMe::PMergeMe( const std::vector<int> & other ) : _dequeChain(other.begin(), other.end()), _vectorChain( other ) { }

PMergeMe::PMergeMe( const PMergeMe & other ) : _dequeChain( other._dequeChain), _vectorChain( other._vectorChain) { }

PMergeMe & PMergeMe::operator=( const PMergeMe & other ) {
	if ( this != &other ) {
		_dequeChain = other._dequeChain;
		_vectorChain = other._vectorChain;
	}
	return *this;
}

PMergeMe::~PMergeMe() { }

void fordJohnson( std::vector<int> chain ) {
	std::vector< std::pair<int, int> > pairs;
	
	if (chain.size() <= 2) {
		
	}
	for ( int i = 0; i <= chain.size() - 2; i+=2 )
		pairs.push_back( std::make_pair( chain[i], chain[i+1]) );
	// tratar straggler
}