#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = false;
}

AForm::~AForm(){
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm & AForm::operator=(const AForm & other)
{
    if(this != &other)
    {
        isSigned = other.isSigned;
    }
    return(*this);
}

const std::string & AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const 
{
    return (isSigned);
}

int AForm::getGradeToSign() const 
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const 
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm & form)
{
    os << "Form: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << ", Is Signed: ";
    if (form.getIsSigned())
        os << "Signed";
    else 
        os << "Not Signed";
    return os;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

