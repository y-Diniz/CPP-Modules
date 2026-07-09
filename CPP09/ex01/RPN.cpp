#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

RPN::RPN() { }

RPN::RPN( const RPN & other ) {
	_numbers = other._numbers;
}

RPN & RPN::operator=( const RPN & other ) {
	if ( this != &other )
		_numbers = other._numbers;

	return *this;
}

RPN::~RPN() { }

// parse

void RPN::parseExpression( char *s ) {

	while ( isspace( (unsigned char)*s ) )
		s++;

	if ( !*s )
		return ;

	if ( !isdigit( *s ) ) {
		applyOperator( *s );
		s++;
		parseExpression( s );
		return ;
	}

	char *end;
	double value = std::strtod( s, &end );

	if ( s == end )
		throw std::runtime_error("Error: Invalid input");
	if ( value >= 10)
		throw std::runtime_error("Error: number must be a single digit (0-9)");

	_numbers.push(value);

	parseExpression( &s[end - s] );
}

void RPN::applyOperator( char op ) {

	double value;
	int i;

	if (_numbers.size() < 2)
		throw std::runtime_error("Error: Invalid input");

	double y = _numbers.top();
	_numbers.pop();

	double x = _numbers.top();
	_numbers.pop();

	char operators[] = {'+', '-', '/', '*'};
	for (i = 0; i < 4; i++) {
		if ( op == operators[i] )
			break;
	}

	if ( y == 0 && op == '/' )
		throw std::runtime_error("Error: Can't divide by zero");

	switch (i) {
		case 0: value = x + y; break;
		case 1: value = x - y; break;
		case 2: value = x / y; break;
		case 3: value = x * y; break;
		default : throw std::runtime_error("Error: Invalid input");
	}
	
	_numbers.push(value);
}

void RPN::getResult() {
	if (_numbers.size() == 1)
		std::cout << _numbers.top() << std::endl;
	else
		throw std::runtime_error("Error: Invalid input");
}