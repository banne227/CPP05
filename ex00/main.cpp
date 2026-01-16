//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : main.cpp                                     #
//#   Created : 2026-01-16 17:39                             #
//#   Updated : 2026-01-16 17:39                             #
//#                                                          #
//############################################################

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Alice", 2);
	std::cout << a << std::endl;

	a.incrementGrade();
	std::cout << a << std::endl;

	a.decrementGrade();
	std::cout << a << std::endl;

	Bureaucrat b("Bob", 1); 
	b.incrementGrade(); // program should throw GradeTooHighException n stop
	
	//Bureaucrat c("David", 150);
	//c.decrementGrade(); // program should throw GradeTooLowException n stop

	return 0;
}
