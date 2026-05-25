#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class ScalarConverter {

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& src );
		ScalarConverter& operator=( const ScalarConverter& src );
		static int convert( const std::string& literal );

};

#endif