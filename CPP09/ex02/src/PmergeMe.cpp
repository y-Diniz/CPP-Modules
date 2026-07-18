#include "../PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>
#include <iostream>
#include <utility>

PmergeMe::PmergeMe() : _size (0) { }

PmergeMe::PmergeMe( const std::vector<int> & other ) : _deque(other.begin(), other.end()), _vector( other ), _size( other.size() ){ }

PmergeMe::PmergeMe( const PmergeMe & other ) : _deque( other._deque), _vector( other._vector), _size( other._size ) { }

PmergeMe & PmergeMe::operator=( const PmergeMe & other ) {
	if ( this != &other ) {
		_deque = other._deque;
		_vector = other._vector;
		_size = other._size;
	}
	return *this;
}

PmergeMe::~PmergeMe() { }

static void printChain( std::vector<int> & chain ) {

	for (size_t i = 0; i < chain.size(); i++) {
		std::cout << chain[i];
		if ( i + 1 < chain.size() )
			std::cout << " ";
	}
		
	std::cout << std::endl;
}

void PmergeMe::processSort() {

	struct timeval start, end;

	gettimeofday(&start, NULL);
	std::vector<int> vectorOrdered = fordJohnson(_vector);
	gettimeofday(&end, NULL);

	long vectorTime = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	std::deque<int> dequeOrdered = fordJohnson(_deque);
	gettimeofday(&end, NULL);

	long dequeTime = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	std::cout << "Before: ";
	printChain(_vector);

	std::cout << "After: ";
	printChain(vectorOrdered);

	std::cout << "Time to process a range of " << _size << " elements with std::vector: " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::deque: " << dequeTime << " us" << std::endl;
}

