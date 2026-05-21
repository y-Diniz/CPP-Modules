#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class AForm {

	private:
		const std::string name_;
		const int grade_to_sign_;
		const int grade_to_exec_;
		bool signed_;

	public:
		AForm();
		virtual ~AForm();
		AForm( const std::string name, const int grade_to_sign, const int grade_to_exec );
		AForm( const AForm& src );
		AForm& operator=( const AForm& src );
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned( const Bureaucrat& b );
		virtual void execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& out, const AForm& f );

#endif