#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template < typename T >
class Array {
	private:
		T * array_;
		unsigned int size_;

	public:
		Array();
		Array( unsigned int n );
		Array( const Array & rhs );
		Array & operator=( const Array & rhs );
		T & operator[]( unsigned int index );
		const T & operator[]( unsigned int index ) const;
		unsigned int size( ) const;
		~Array();
};

#include "Array.tpp"

#endif