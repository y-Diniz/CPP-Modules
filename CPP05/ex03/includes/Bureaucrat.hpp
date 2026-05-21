#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat {

	private:
		std::string name_;
		int grade_;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const Bureaucrat& src );
		Bureaucrat& operator=( const Bureaucrat& src );
		void incrementGrade();
		void decrementGrade();
		int getGrade() const;
		const std::string& getName() const;
		void signForm( AForm& f );
		void executeForm( const AForm& form ) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b );

#endif