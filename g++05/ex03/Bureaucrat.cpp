#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : name(other.name)
{
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat & other)
{
    if(this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void    Bureaucrat::incrementGrade()
{
    if (this->grade > 1)
        this->grade--;
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    if (this->grade < 150)
        this->grade++;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return os;
}

void    Bureaucrat::signForm(AForm & form)
{
    try 
    {
        form.beSigned(*this);
        std::cout << *this << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << *this << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " cannot execute " << form.getName() << "because: " << e.what() << std::endl;
    }
}