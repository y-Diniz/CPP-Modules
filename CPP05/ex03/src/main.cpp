#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {

	{
		Bureaucrat b( "Marlin", 1);
		Intern randomIntern;
		std::cout << std::endl;
		AForm* forms[4];

		for ( int i = 0; i < 4; i++)
			forms[i] = NULL;

		try {

			forms[0] = randomIntern.makeForm( "Presidential", "Ross" );
			std::cout << std::endl;
			forms[1] = randomIntern.makeForm( "Robotomy", "Bolsonoro" );
			std::cout << std::endl;
			forms[2] = randomIntern.makeForm( "Shrubbery", "mar" );
			std::cout << std::endl;
			forms[3] = randomIntern.makeForm( "Random", "error" );
			std::cout << std::endl;

		} catch ( std::exception& e ) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {

			for (int i = 0; i < 4; i++)
				if (forms[i]) {
					b.signForm(*forms[i]);
					b.executeForm(*forms[i]);
					std::cout << std::endl;
				}

		} catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
		}

		for ( int i = 0; i < 4; i++)
			delete forms[i];
	}
	return 0;
}