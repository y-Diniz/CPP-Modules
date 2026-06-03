#ifndef ARRAY_TPP
#define ARRAY_TPP


template < typename T>
Array<T>::Array( ) : array_( NULL ), size_( 0 ) { }

template < typename T>
Array<T>::Array( unsigned int n ) : size_( n ) {
	array_ = new T[ n ];
}

template < typename T>
Array<T>::Array( const Array & lhs ) : size_( lhs.size_ ) {
	array_ = new T[ size_ ];
	for ( unsigned int i = 0; i < size_; i++ )
		array_[ i ] = lhs.array_[ i ];
}

template < typename T>
Array<T> & Array<T>::operator=( const Array<T> & lhs ) {
	if ( this != &lhs ) {
		delete[] array_;
		size_ = lhs.size_;
		array_ = new T[ size_ ];
		for ( unsigned int i = 0; i < size_; i++ )
			array_[ i ] = lhs.array_[ i ];
	}
	return *this;
}

template < typename T>
T & Array<T>::operator[]( unsigned int index ) {
	if (index >= size_)
		throw std::exception();
	return array_[ index ];
}

template < typename T>
const T & Array<T>::operator[]( unsigned int index ) const {
	if (index >= size_)
		throw std::exception();
	return array_[ index ];
}

template < typename T>
unsigned int Array<T>::size( ) const {
	return size_;
}

template < typename T>
Array<T>::~Array( ) {
	delete[] array_;
}

#endif