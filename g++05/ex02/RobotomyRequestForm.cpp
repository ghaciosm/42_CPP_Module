#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm(other)
{
    this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if(!getIsSigned())
        throw AForm::FormNotSignedException();
    else if(executor.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    if (rand() % 2 == 0) 
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomize process failed for " << target << "." << std::endl;
}