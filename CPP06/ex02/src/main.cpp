#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate( ) {

	Base *p = NULL;

	int n = rand() % 3;

	switch (n) {
		case 0: p = new A; break;
		case 1: p = new B; break;
		case 2: p = new C; break;
	}
	return (p);
}

void identify( Base* p ) {

	if (dynamic_cast<A*>(p))
		std::cout << "The type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type is C" << std::endl;
	else
		std::cout << "Casting Failed" << std::endl;
}

void identify( Base& p ) {
	
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "The type is A" << std::endl;
		return;
	} catch ( std::exception & e ) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "The type is B" << std::endl;
		return;
	} catch ( std::exception & e ) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "The type is C" << std::endl;
		return;
	} catch ( std::exception & e ) { }
}

int main( ) {

	std::srand(std::time(0));
	Base *p = generate();

	std::cout << "Grep type by pointer:" << std::endl;
	identify( p );

	std::cout << "Grep type by ref:" << std::endl;
	identify( *p );

	delete p;

	return 0;
}