//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Intern.hpp                                   #
//#   Created : 2026-01-20 10:51                             #
//#   Updated : 2026-01-20 10:51                             #
//#                                                          #
//############################################################

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef enum FormType
{
	SHRUBBERY_CREATION = 0,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	UNKNOWN_FORM
} FormType;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& formName, const std::string& target);
};