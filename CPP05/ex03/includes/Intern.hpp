#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern {

	public:
		Intern();
		~Intern();
		Intern( const Intern& src );
		Intern& operator=( const Intern& src );
		AForm* makeForm( const std::string& form_name, const std::string& target );

		class FormDoesNotExist : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif