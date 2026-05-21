#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern Constructor default called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern( const Intern& src ) {
	std::cout << "Intern Copy constructor called" << std::endl;

	(void)src;
}

Intern& Intern::operator=( const Intern& src ) {
	std::cout << "Intern Operator= called" << std::endl;

	(void)src;
	return *this;
}

AForm* Intern::makeForm( const std::string& form_name, const std::string& target ) {

	std::string names[] = { "Presidential", "Robotomy", "Shrubbery" };

	int i;
	for ( i = 0; i < 3; i++ )
		if ( names[i] == form_name)
			break ;

	if ( i < 3)
		std::cout << "Intern makes " << names[i] << std::endl;

	switch (i) {
		case 0: return new PresidentialPardonForm( target );
		case 1: return new RobotomyRequestForm( target );
		case 2: return new ShrubberyCreationForm( target );
		default: throw FormDoesNotExist();
	}
}

const char* Intern::FormDoesNotExist::what() const throw () {
	return "Error: Form does not exist";
}
