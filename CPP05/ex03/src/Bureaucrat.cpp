#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name_( "Unknown" ), grade_( 1 ) {
	std::cout << "Bureaucrat Constructor default called" << std::endl;
}

Bureaucrat::~Bureaucrat( ) {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : name_( name ) {
	std::cout << "Bureaucrat Constructor called" << std::endl;

	if ( grade < 1 )
		throw GradeTooHighException( );
	if ( grade > 150 )
		throw GradeTooLowException( );
	grade_ = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : name_( src.name_ ), grade_( src.grade_ ){
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src ) {
	std::cout << "Bureaucrat Operator= called" << std::endl;

	if ( this != &src )
	{
		name_ = src.getName( );
		grade_ = src.getGrade( );
	}
	return *this;
}

const std::string& Bureaucrat::getName( ) const {
	return name_;
}

int Bureaucrat::getGrade( ) const {
	return grade_;
}

void Bureaucrat::incrementGrade( ) {
	std::cout << this->name_ << "'s grade was increased" << std::endl;

	if ( ( grade_ - 1) < 1 )
		throw GradeTooHighException( );
	grade_ -= 1;
}

void Bureaucrat::decrementGrade( ) {
	std::cout << this->name_ << "'s grade was decreased" << std::endl;

	if ( ( grade_ + 1) > 150 )
		throw GradeTooLowException( );
	grade_ += 1;
}

const char* Bureaucrat::GradeTooHighException::what( ) const throw( ) {
	return "Error: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what( ) const throw( ) {
	return "Error: Grade too low";
}

void Bureaucrat::signForm( AForm& f ) {
	try {
		f.beSigned( *this );
		std::cout << name_ << " signed " << f.getName() << std::endl;
	} catch ( const std::exception& e ) {
		std::cout << name_ << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( const AForm& form ) const {
	try {
		form.execute( *this );
		std::cout << name_ << " executed " << form.getName() << std::endl;
	} catch ( const std::exception& e ) {
		std::cout << name_ << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b ) {
	out << b.getName( ) << ", burocrata com classificação " << b.getGrade();
	return out;
}