#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	
	private:
		std::string target_;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
		void execute( const Bureaucrat& executor ) const;
		
};

#endif