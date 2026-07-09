#include "RPN.hpp"
#include <iostream>

int main( int ac, char**av ) {

	if ( ac != 2) {
		std::cout << "Usage: build/RPN '<inverted Polish mathematical expression>'" << std::endl;
		return 1;
	}

	RPN a;

	try {
		a.parseExpression( av[1] );
		a.getResult();
	} catch ( const std::exception & e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}