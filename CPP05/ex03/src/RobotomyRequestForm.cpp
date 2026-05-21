#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm( "Robotomy", 72, 45 ) {
	std::cout << "Robotomy Constructor default called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm( "Robotomy", 72, 45 ), target_( target ) {
	std::cout << "Robotomy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm( src ) {
	std::cout << "Robotomy Copy constructor called" << std::endl;

	target_ = src.target_;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src ) {
	std::cout << "Robotomy Operator= called" << std::endl;
	
	if ( this != &src )
		target_ = src.target_;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if ( !this->isSigned() )
		throw AForm::FormNotSignedException();

	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();

	std::srand( std::time(0) );
	bool res = std::rand() % 2;

	std::cout << "✨ drilling noises ✨" << std::endl;
	if (res)
		std::cout << target_ << " has been robotomized successfully! 🥴" << std::endl;
	else
		std::cout << target_ << " robotomy failed!" << std::endl;
}