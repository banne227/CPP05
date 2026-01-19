#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzz... Vrrrrr... (drilling noises)" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
