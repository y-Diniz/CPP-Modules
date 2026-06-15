#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : n_(0) { }

Span::Span( unsigned int n ) : n_(n) { }

Span::Span( const Span & rhs ) : n_(rhs.n_), span_(rhs.span_) { }

Span & Span::operator=( const Span & rhs ) {
	if (this != &rhs) {
		n_ = rhs.n_;
		span_ = rhs.span_;
	}

	return *this;
}

Span::~Span() { }

void Span::addNumber( int n ) {
	if (span_.size() >= n_)
		throw FullSpanException();

	span_.push_back(n);
}

void	Span::addRangeNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	if (span_.size() + std::distance(begin, end) > n_)
		throw FullSpanException();

	span_.insert(span_.end(), begin, end);
}

void Span::push( unsigned int n ) {
	if (span_.size() + n > n_)
		throw FullSpanException();

	for (unsigned int i = 0; i < n; i++)
		addNumber(rand());
}

unsigned int Span::diff( unsigned int i ) const {
	long long x = static_cast<long long>(span_[i+1]);
	long long y = static_cast<long long>(span_[i]);
	
	return static_cast<unsigned int>(x - y);
}

unsigned int Span::shortestSpan() {
	unsigned int size = span_.size();

	if (size < 2)
		throw NoSpanFoundException();

	std::sort(span_.begin(), span_.end());

	unsigned int temp = diff(0);

	for (unsigned int i = 0; (i+1) < size; i++) {
		if (diff(i) < temp)
			temp = diff(i);
	}

	return temp;
}

unsigned int Span::longestSpan() const {
	if (span_.size() < 2)
		throw NoSpanFoundException();

	long long min = *(std::min_element(span_.begin(), span_.end()));
	long long max = *(std::max_element(span_.begin(), span_.end()));

	return static_cast<unsigned int>(max - min);
}

const std::vector<int> &Span::getSpan() const {
	return span_;
}

const char* Span::FullSpanException::what() const throw() {
	return "Error: Span already full";
}

const char* Span::NoSpanFoundException::what() const throw() {
	return "Error: No span found";
}