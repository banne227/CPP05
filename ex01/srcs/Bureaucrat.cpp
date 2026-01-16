//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Bureaucrat.cpp                               #
//#   Created : 2026-01-16 17:12                             #
//#   Updated : 2026-01-16 17:12                             #
//#                                                          #
//############################################################

#include "../includes/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade >= 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}