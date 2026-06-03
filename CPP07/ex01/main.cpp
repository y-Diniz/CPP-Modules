#include "Iter.hpp"
#include <string>

int main() {

	{
		std::cout << "INT TEST" << std::endl;

		int array[] = { 1, 2, 3 };

		std::cout << "Array before iter: " << std::endl;
		::iter( array, 3, print<int> );

		::iter( array, 3, plusOne<int> );

		std::cout << "Array after iter: " << std::endl;
		::iter( array, 3, print<int> );

		std::cout << std::endl;
	}

	{
		std::cout << "DOUBLE TEST" << std::endl;

		double array[] = { 1.9, 2.7, 3.3 };

		std::cout << "Array before iter: " << std::endl;
		::iter( array, 3, print<double> );
		
		::iter( array, 3, plusOne<double> );

		std::cout << "Array after iter: " << std::endl;
		::iter( array, 3, print<double> );

		std::cout << std::endl;
	}

	{
		std::cout << "FLOAT TEST" << std::endl;

		float array[] = { 3.7f, 4.4f, 9.1f };

		std::cout << "Array before iter: " << std::endl;
		::iter( array, 3, print<float> );
		
		::iter( array, 3, plusOne<float> );

		std::cout << "Array after iter: " << std::endl;
		::iter( array, 3, print<float> );

		std::cout << std::endl;
	}

	{
		std::cout << "STRING TEST" << std::endl;

		std::string array[] = { "Hello", "World" };

		std::cout << "Array before iter: " << std::endl;
		::iter( array, 2, print<std::string> );
		
		::iter( array, 2, addExclamation<std::string> );

		std::cout << "Array after iter: " << std::endl;
		::iter( array, 2, print<std::string> );
	}

	return  0;
}