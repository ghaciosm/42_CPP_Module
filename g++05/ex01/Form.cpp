#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if(gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form & other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form & other)
{
    if(this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

std::string Form::getName() const
{
    return (name);
}

bool    Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return  (gradeToExecute);
}

void    Form::beSigned(const Bureaucrat & bur)
{
    if(bur.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form & form)
{
    os << form.getName() << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << ", Is Signed: ";
    
    if(form.getIsSigned())
        os << "Signed" << std::endl;
    else
        os << "Not Signed" << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}