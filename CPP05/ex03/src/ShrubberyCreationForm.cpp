#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm( "Shrubbery", 145, 137 ) {
	std::cout << "Shrubbery constructor default called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm( "Shrubbery", 145, 137 ), target_( target ) {
	std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ) {
	std::cout << "Shrubbery copy constructor called" << std::endl;

	target_ = src.target_;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src ) {
	std::cout << "Shrubbery operator= called" << std::endl;

	if ( this != &src )
		target_ = src.target_;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if ( !this->isSigned() )
		throw AForm::FormNotSignedException();

	if ( executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream file( (target_ + "_shrubbery").c_str() );
	if (!file)
    	throw std::runtime_error("Cannot create file");

	const std::string tree =
	"                                                         .                                                        .\n"
	"                                              .         ;                                              .         ;\n"
	"                 .              .              ;%     ;;                   .             .              ;%     ;;\n"
	"                   ,           ,                :;%  %;                      ,          ,                :;%  %;\n"
	"                    :         ;                   :;%;'     .,                :       ;                   :;%;'     .,\n"
	"           ,.        %;     %;            ;        %;'    ,;       ,.        %;    %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,'          ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,'             %;       %;%;      ,  ;       %;  ;%;   ,%'\n"
	"               ;%;      %;        ;%;        % ;%;  ,'                ;%;      %;        ;%;        % ;%;  ,%'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'                 `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'                     `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'                          `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'                              `@%:.  :;%.         ;@@%;'\n"
	"                        `@%.  `;@%.      ;@@%;                                  `@%.  `;@%.      ;@@%;\n"
	"                          `@%%. `@%%    ;@@%;                                      `@%%. `@%%    ;@@%;\n"
	"                            ;@%. :@%%  %@@%;                                         ;@%. :@%%  %@@%;\n"
	"                              %@bd%%%bd%%:;                                             %@bd%%%bd%%:;\n"
	"                                #@%%%%%:;;                                               #@%%%%%:;;\n"
	"                                %@@%%%::;                                                 %@@%%%::;\n"
	"                                %@@@%(o);  . '                                            %@@@%(o);  . '\n"
	"                                %@@@o%;:(.,'                                              %@@@o%;:(.,'\n"
	"                            `.. %@@@o%::;                                             `.. %@@@o%::;\n"
	"                               `)@@@o%::;                                                `)@@@o%::;\n"
	"                                %@@(o)::;                                                 %@@(o)::;\n"
	"                               .%@@@@%::;                                                .%@@@@%::;\n"
	"                               ;%@@@@%::;.                                               ;%@@@@%::;.\n"
	"                              ;%@@@@%%:;;;.                                             ;%@@@@%%:;;;.\n"
	"                          ...;%@@@@@%%:;;;;,..                                      ...;%@@@@@%%:;;;;,..";
	
	file << tree;
	file.close();
}