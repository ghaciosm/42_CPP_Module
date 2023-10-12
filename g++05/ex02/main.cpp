#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    std::cout << std::endl;
    Bureaucrat bureaucrat("John", 50);
    std::cout << bureaucrat << std::endl;

    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("criminal");

    bureaucrat.signForm(shrubberyForm);
    bureaucrat.signForm(robotomyForm);
    bureaucrat.signForm(pardonForm);

    std::cout << std::endl;
    bureaucrat.executeForm(shrubberyForm);
    std::cout << std::endl;
    bureaucrat.executeForm(robotomyForm);
    std::cout << std::endl;
    bureaucrat.executeForm(pardonForm);
    std::cout << std::endl;

    return 0;
}