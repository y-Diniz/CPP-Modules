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

std::vector< int > fordJohnson( const std::vector<int> & chain ) {

	size_t size = chain.size();
	
	if (size == 1)
		return chain;
	if (size == 2) {
		if (chain[0] > chain[1]) {
			std::vector< int > ordered;
			ordered.push_back(chain[1]);
			ordered.push_back(chain[0]);
			return ordered;
		}
		else
			return chain;
	}

	std::vector< std::pair<int, int> > pairs;
	size_t i;

	for ( i = 0; i <= size - 2; i+=2 )
		pairs.push_back( std::make_pair( chain[i], chain[i+1]) );

	// comparar pares e separar em winners e losers

	std::vector< int > ordered_winners = fordJohnson( winners );

	// inserir perdedores em ordered_winners

	if ( size % 2 != 0 )
		// inserir o straggler (chain[i]) no ordered_winners

	return ordered_winners;
}