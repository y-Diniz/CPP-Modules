#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
	private:
		unsigned int n_;
		std::vector<unsigned int> span_;
	
	public:
		Span();
		Span( unsigned int n );
		Span( const Span & rhs );
		Span & operator=( const Span & rhs );
		~Span();
		void addNumber( unsigned int n );
		void push( unsigned int n );
		void addRangeNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::vector<unsigned int> &getSpan();

		class FullSpanException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NoSpanFoundException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif