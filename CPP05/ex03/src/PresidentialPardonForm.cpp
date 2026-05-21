#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm( "Presidential", 25, 5 ) {
	std::cout << "Presidential Constructor default called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm( "Presidential", 25, 5 ), target_( target ) {
	std::cout << "Presidential Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm( src ) {
	std::cout << "Presidential Copy constructor called" << std::endl;
	
	target_ = src.target_;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src ) {
	std::cout << "Presidential Operator= called" << std::endl;

	if ( this != &src )
		target_ = src.target_;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if ( !this->isSigned() )
		throw AForm::FormNotSignedException();

	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();

	std::cout << target_ << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}