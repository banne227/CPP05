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
#include <cstdlib>
#include <ctime>

#include "includes/Bureaucrat.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
    // Initialize random number generator
    std::srand(std::time(NULL));

    try
    {
        std::cout << "=== Creation of bureaucrats ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        std::cout << boss << std::endl;
        std::cout << intern << std::endl;

        std::cout << "\n=== Création des formulaires ===" << std::endl;
        ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
        RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;

        std::cout << "\n=== Tests de signature ===" << std::endl;
        intern.signForm(shrub);   // OK (150 <= 145 ? no → failure)
        boss.signForm(shrub);     // OK

        boss.signForm(robot);     // OK
        boss.signForm(pardon);    // OK

        std::cout << "\n=== Tests d'exécution ===" << std::endl;

        intern.executeForm(shrub); // failure (grade too low)
        boss.executeForm(shrub);   // OK → creates the file

        boss.executeForm(robot);   // 50% success / failure
        boss.executeForm(robot);   // another random test
        boss.executeForm(pardon);  // OK → pardon message
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
