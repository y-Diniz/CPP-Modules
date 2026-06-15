#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack() { }

		MutantStack( const MutantStack<T> & rhs ) : std::stack<T>(rhs) {}

		MutantStack<T>& operator=( const MutantStack<T> & rhs ) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		~MutantStack() {}
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

};