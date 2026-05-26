#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter( const ScalarConverter & src ) { (void)src; }

ScalarConverter& ScalarConverter::operator=( const ScalarConverter & src ) { 
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() { }


void ScalarConverter::convert( const std::string & literal ) {
	
	double n;

	if (literal.empty()) {
		std::cout << "Error: invalid input" << std::endl;
		return;
	}

	if (literal.size() == 1 && std::isalpha(literal[0]))
		n = static_cast<double>(literal[0]);
	else {
		char* end;
		n = std::strtod( literal.c_str(), &end );

		if ( ( *end != '\0' && *end != 'f' ) || ( *end == 'f' && *( end + 1 ) != '\0' ) ) {
			std::cout << "Error: invalid input" << std::endl;
			return ;
		}
	
	}
	printChar( n );
	printInt( n );
	printFloatingPoint( n );
}

void ScalarConverter::printInt( const double n ) {
	if ( n < INT_MIN || n > INT_MAX || std::isnan(n) || std::isinf(n) )
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

void ScalarConverter::printChar( const double n ) {
	if ( n < 0 || n > 127 || std::isnan(n) || std::isinf(n) )
		std::cout << "char: Impossible" << std::endl;
	else if ( !std::isprint( static_cast<char>(n) ) )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
}

void ScalarConverter::printFloatingPoint( const double n ) {
	if ( std::isnan(n) || std::isinf(n) ) {
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << n << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
	}
}