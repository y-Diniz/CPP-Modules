#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template < typename T >
typename T::iterator easyfind( T & container, int value ) {

	typename T::iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == value)
			return it;
	}

	return container.end();
}

#endif
