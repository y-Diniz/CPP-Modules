#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter & src );
		ScalarConverter& operator=( const ScalarConverter & src );
		~ScalarConverter();

		static void printInt( const double n );
		static void printChar( const double n );
		static void printFloatingPoint( const double n );

	public:
		static void convert( const std::string & literal );

};

#endif