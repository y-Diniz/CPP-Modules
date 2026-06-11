#include "Span.hpp"
#include <cstdlib>
#include <iostream>

#define MAX_INT 20000

int main() {

	std::srand(time(0));

	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span s(10);

		for (int i = 0; i < 10; i++) {

			try {
				s.addNumber(i);
			} catch (std::exception & e) {
				std::cout << e.what() << std::endl;
			}

		}

		std::cout << "The logest span is " << s.longestSpan() << std::endl;
		std::cout << "The shortest span is " << s.shortestSpan() << std::endl;
	}

	
	{
		Span s(10000);

		s.push(10000);

		std::cout << "The logest span is " << s.longestSpan() << std::endl;
		std::cout << "The shortest span is " << s.shortestSpan() << std::endl;
	}

	{
		Span s(MAX_INT);

		s.push(MAX_INT);

		std::cout << "The logest span is " << s.longestSpan() << std::endl;
		std::cout << "The shortest span is " << s.shortestSpan() << std::endl;
	}

	return 0;
}