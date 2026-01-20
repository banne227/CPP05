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
#include "includes/Intern.hpp"

int main()
{
    // Initialize random number generator
    std::srand(std::time(NULL));

    std::cout << "===== INTERN CREATION TEST =====" << std::endl;

    Intern intern;
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* form4 = NULL;

    form1 = intern.makeForm("shrubbery creation", "home");
    form2 = intern.makeForm("robotomy request", "Bender");
    form3 = intern.makeForm("presidential pardon", "Arthur Dent");
    form4 = intern.makeForm("unknown form", "nobody");

    std::cout << "\n===== BUREAUCRAT TEST =====" << std::endl;

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 150);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    std::cout << "\n===== SIGN / EXECUTE TEST =====" << std::endl;

    if (form1)
    {
        worker.signForm(*form1);
        boss.signForm(*form1);
        boss.executeForm(*form1);
    }
    std::cout << std::endl;
    if (form2)
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
    }
    std::cout << std::endl;
    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
    }

    return 0;
}

