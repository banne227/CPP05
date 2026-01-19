//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : AForm.cpp                                     #
//#   Created : 2026-01-16 18:58                             #
//#   Updated : 2026-01-16 18:58                             #
//#                                                          #
//############################################################

#include "../includes/AForm.hpp"

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) 
: _name(name), sign(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
:_name(other._name),
 sign(other.sign),
 grade_to_sign(other.grade_to_sign),
 grade_to_execute(other.grade_to_execute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->sign;
}

int AForm::getGradeToSign() const
{
	return this->grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw GradeTooLowException();
	else
		this->sign = true;
}

void AForm::execute(Bureaucrat const& bureaucrat) const
{
	if (this->sign == false)
		throw FormNotSign();
	if (bureaucrat.getGrade() > this->grade_to_execute)
		throw CannotExecute();

	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;
    return os;
}