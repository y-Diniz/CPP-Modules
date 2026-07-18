#include "../PmergeMe.hpp"
#include <iostream>
#include <string>

std::vector<int> chainParser( char **av );

int main( int ac, char **av ) {

	if (ac == 1) {
		std::cout << "Usage: ./build/PmergeMe <numbers chain>" << std::endl;
		return 1;
	}
	try {
		std::vector<int> chain = chainParser( av + 1 );
		PmergeMe sort(chain);
		sort.processSort();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
}
