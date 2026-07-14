#include "PMergeMe.hpp"
#include <iostream>
#include <string>

std::vector<int> chainParser( char **av );
std::string errorMessage( std::string message, std::string param );

int main( int ac, char **av ) {

	if (ac == 1) {
		std::cout << "Usage: ./build/PMergeMe <numbers chain>" << std::endl;
		return 1;
	}
	try {
		std::vector<int> chain = chainParser( av + 1 );
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
}
