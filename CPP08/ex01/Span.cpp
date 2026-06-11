#include "Span.hpp"
#include <algorithm>

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

void Span::addNumber( unsigned int n ) {
	if (span_.size() >= n_)
		throw FullSpanException();
	span_.push_back(n);
}

void Span::push( unsigned int n ) {
	if (span_.size() + n > n_)
		throw FullSpanException();
	for (unsigned int i = 0; i < n; i++)
		addNumber(rand());
}

unsigned int Span::shortestSpan() {
	std::sort(span_.begin(), span_.end());
	unsigned int temp = span_[1] - span_[0];
	for (unsigned int i = 0; (i+1) < n_; i++) {
		if ((span_[i+1] - span_[i]) < temp)
			temp = span_[i+1] - span_[i];
	}
	return temp;
}

unsigned int Span::longestSpan() {
	unsigned int min = *(std::min_element(span_.begin(), span_.end()));
	unsigned int max = *(std::max_element(span_.begin(), span_.end()));
	return max - min;
}

const char* Span::FullSpanException::what() const throw() {
	return "Error: Span already full";
}

const char* Span::NoSpanFoundException::what() const throw() {
	return "Error: No span found";
}