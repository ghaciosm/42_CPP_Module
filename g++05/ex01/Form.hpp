#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form
{
    private:
        const std::string name;
        bool   isSigned;
        const int gradeToSign;
        const int gradeToExecute; 
    public:
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form & other);
        Form& operator=(const Form & other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void    beSigned(const Bureaucrat & bur);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif