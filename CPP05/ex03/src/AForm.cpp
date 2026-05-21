#include "AForm.hpp"
#include <iostream>

AForm::AForm() : name_( "Unknow" ), grade_to_sign_( 1 ), grade_to_exec_( 1 ), signed_( false ) {
	std::cout << "AForm Constructor default called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm( const std::string name, const int grade_to_sign, const int grade_to_exec ) : name_( name ), grade_to_sign_( grade_to_sign ), grade_to_exec_( grade_to_exec ), signed_( false ) {
	std::cout << "AForm Constructor called" << std::endl;

	if ( grade_to_sign < 1 || grade_to_exec < 1 )
		throw GradeTooHighException();
	if ( grade_to_sign > 150 || grade_to_exec > 150 )
		throw GradeTooLowException();
}

AForm::AForm( const AForm& src ) : name_( src.name_ ), grade_to_sign_( src.grade_to_sign_ ), grade_to_exec_( src.grade_to_exec_ ), signed_( src.signed_ ) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=( const AForm& src ) {
	std::cout << "AForm Operator= called" << std::endl;

	if (this != &src)
		signed_ = src.signed_;
	return *this;
}

const std::string& AForm::getName() const {
	return name_;
}

bool AForm::isSigned() const {
	return signed_;
}

int AForm::getGradeToSign() const {
	return grade_to_sign_;
}

int AForm::getGradeToExecute() const {
	return grade_to_exec_;
}


void AForm::beSigned( const Bureaucrat& b ) {
	if ( b.getGrade() > grade_to_sign_ )
		throw GradeTooLowException();
	signed_ = true;
}

const char* AForm::GradeTooHighException::what( ) const throw( ) {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what( ) const throw( ) {
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what( ) const throw( ) {
	return "form is not signed";
}

std::ostream& operator<<( std::ostream& out, const AForm& f ) {
	out << "Form: " << f.getName()  << "; Grade to sign: " << f.getGradeToSign() << "; Grade to exec: " << f.getGradeToExecute() << "; Is signed: " << f.isSigned();
	return out;
}