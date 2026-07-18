#include "PMergeMe.hpp"
#include <utility>

PMergeMe::PMergeMe() { }

PMergeMe::PMergeMe( const std::vector<int> & other ) : _deque(other.begin(), other.end()), _vector( other ) { }

PMergeMe::PMergeMe( const PMergeMe & other ) : _deque( other._deque), _vector( other._vector) { }

PMergeMe & PMergeMe::operator=( const PMergeMe & other ) {
	if ( this != &other ) {
		_deque = other._deque;
		_vector = other._vector;
	}
	return *this;
}

PMergeMe::~PMergeMe() { }

