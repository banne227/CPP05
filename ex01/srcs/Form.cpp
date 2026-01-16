//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Form.cpp                                     #
//#   Created : 2026-01-16 18:58                             #
//#   Updated : 2026-01-16 18:58                             #
//#                                                          #
//############################################################

#include "../includes/Form.hpp"

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) 
: _name(name), sign(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
:_name(other._name),
 sign(other.sign),
 grade_to_sign(other.grade_to_sign),
 grade_to_execute(other.grade_to_execute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->sign;
}

int Form::getGradeToSign() const
{
	return this->grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw GradeTooLowException();
	else
		this->sign = true;
}

void Form::signForm(const Bureaucrat& bureaucrat)
{
	try
	{
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName()
				  << " because " << e.what() << std::endl;
	}
}