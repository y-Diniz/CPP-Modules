#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

#define MAX_INT 20000

int main() {

	std::srand(time(0));

	{
		std::cout << "Test: FullSpanException" << std::endl;
		try {
			Span small(2);
			small.addNumber(1);
			small.addNumber(2);
			small.addNumber(3);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "Test: NoSpanFoundException" << std::endl;
		try {
			Span empty(5);
			empty.addNumber(1);
			empty.shortestSpan();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "The longest span is " << sp.longestSpan() << std::endl;
		std::cout << "The shortest span is " << sp.shortestSpan() << std::endl;

		Span s(10);
		try {
			s.addRangeNumber(sp.getSpan().begin(), sp.getSpan().end());
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "The longest span is " << s.longestSpan() << std::endl;
		std::cout << "The shortest span is " << s.shortestSpan() << std::endl;
	}

	{
		Span s(MAX_INT);

		s.push(MAX_INT);

		std::cout << "The longest span is " << s.longestSpan() << std::endl;
		std::cout << "The shortest span is " << s.shortestSpan() << std::endl;
	}

	return 0;
}