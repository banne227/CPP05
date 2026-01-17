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
#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main()
{
	std::cout << "== Construct valid bureaucrat ==" << std::endl;
	Bureaucrat alice("Alice", 2);
	std::cout << alice << std::endl;

	std::cout << "-- increment to top --" << std::endl;
	alice.incrementGrade();
	std::cout << alice << std::endl;

	std::cout << "-- decrement back --" << std::endl;
	alice.decrementGrade();
	std::cout << alice << std::endl;

	std::cout << "== Invalid increments/decrements ==" << std::endl;
	Bureaucrat bob("Bob", 1);
	bob.incrementGrade();
	Bureaucrat dave("Dave", 150);
	dave.decrementGrade();

	std::cout << "== Invalid bureaucrat constructors ==" << std::endl;
	
	try { Bureaucrat 
		badHigh("TooHigh", 0); } 
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	
	try { Bureaucrat badLow("TooLow", 151); } 
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n== Forms signing ==" << std::endl;
	Form leaveForm("Leave", 10, 5);
	Form urgentForm("Urgent", 2, 2);

	Bureaucrat charlie("Charlie", 20);
	charlie.signForm(leaveForm);   // too low to sign
	charlie.signForm(urgentForm);  // too low to sign

	std::cout << "-- Alice tries signing --" << std::endl;
	alice.signForm(leaveForm);     // should succeed
	alice.signForm(urgentForm);    // should succeed (alice is grade 2 now)

	std::cout << "== Invalid form constructors ==" << std::endl;
	
	try { Form badFormHigh("BadHigh", 0, 10); } 
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	
	try { Form badFormLow("BadLow", 151, 10); } 
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	return 0;
}
