#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T, typename F >
void iter( T * array, const int lengh, F func ) {
	for (int i = 0; i < lengh; i++) {
		func(array[i]);
	}
}

template < typename T >
void plusOne( T & a ) {
	a += 1;
}

template < typename T >
void addExclamation( T & a ) {
    a += "!";
}

template < typename T >
void print( const T & a ) {
	std::cout << a << std::endl;
}

#endif