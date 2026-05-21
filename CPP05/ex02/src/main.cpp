#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {

	{
		std::cout << "BUREAUCRAT CREATION" << std::endl;
		Bureaucrat a( "Augusto", 50 );

		std::cout << std::endl << "FORMS CREATION" << std::endl;
		ShrubberyCreationForm s( "amazonia" );
		RobotomyRequestForm r( "bolsonaro" );
		PresidentialPardonForm p( "robert" );

		std::cout << std::endl << "SIGN FORMS" << std::endl;
		a.signForm( s );
		a.signForm( r );
		a.signForm( p );

		std::cout << std::endl << "EXEC FORMS" << std::endl;
		a.executeForm( s );
		a.executeForm( r );
		a.executeForm( p );
		std::cout << std::endl << "DESTRUCTION" << std::endl;
	}

	{
		std::cout << "BUREAUCRAT CREATION" << std::endl;
		Bureaucrat a( "Anne", 1 );

		std::cout << std::endl << "FORMS CREATION" << std::endl;
		ShrubberyCreationForm s( "amazonia" );
		RobotomyRequestForm r( "bolsonaro" );
		PresidentialPardonForm p( "neon" );

		std::cout << std::endl << "SIGN FORMS" << std::endl;
		a.signForm( s );
		a.signForm( r );
		a.signForm( p );

		std::cout << std::endl << "EXEC FORMS" << std::endl;
		a.executeForm( s );
		a.executeForm( r );
		a.executeForm( p );
		std::cout << std::endl << "DESTRUCTION" << std::endl;
	}
	
	return 0;
}