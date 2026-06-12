#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack() { }

		MutantStack( const MutantStack<T> & rhs ) : std::stack<T>(rhs) {}

		MutantStack<T> operator=( const MutantStack<T> & rhs ) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		~MutantStack() {}
		
		typedef std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return std::stack<T>::c.begin();
		}

		iterator end() {
			return std::stack<T>::c.end();
		}

};