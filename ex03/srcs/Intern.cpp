//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Intern.cpp                                     #
//#   Created : 2026-01-20 10:56                             #
//#   Updated : 2026-01-20 10:56                             #
//#                                                          #
//############################################################

#include "../includes/Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

Intern::Intern(const Intern& other) 
{
	(void)other;
};

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormType formType = UNKNOWN_FORM;
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			formType = FormType(i);
			break;
		}
	}
	switch (formType)
	{
		case SHRUBBERY_CREATION:
			std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
			return new ShrubberyCreationForm(target);
		case ROBOTOMY_REQUEST:
			std::cout << "Intern creates Robotomy Request Form" << std::endl;
			return new RobotomyRequestForm(target);
		case PRESIDENTIAL_PARDON:
			std::cout << "Intern creates Presidential Pardon Form" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern could not create form: Unknown form name '" << formName << "'" << std::endl;
			return NULL;
	}
}