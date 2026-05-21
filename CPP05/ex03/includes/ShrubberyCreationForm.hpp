#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
	
	private:
		std::string target_;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& src );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& src );
		void execute( const Bureaucrat& executor ) const;

};

#endif