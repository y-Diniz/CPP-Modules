#include <cctype>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <vector>

std::string errorMessage( std::string message, std::string param ) {
	return "Error: " + message + " " + param;
}

std::vector<int> chainParser( char **av ) {
	
	std::vector<int> chain;
	char *end;

	for ( int i = 0; av[i]; i++ ) {
		long int n = strtol( av[i], &end, 10 );

		if ( end == &(av[i][0]) )
			throw std::runtime_error( "Error: coudn't convert" );

		if ( *end != '\0' ) {
			while ( *end ) {
				if ( !isspace( static_cast<unsigned char>(*end) ) )
					throw std::runtime_error( errorMessage( "invalid input:", av[i] ) );
				end++;	
			}
		}

		if (n < 0 || n > INT_MAX )
			throw std::runtime_error( errorMessage( "number off limits:", av[i] ) );

		chain.push_back( static_cast<int>(n) );
	}

	return chain;
}