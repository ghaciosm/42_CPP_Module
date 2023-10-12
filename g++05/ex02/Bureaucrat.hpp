#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat& operator=(const Bureaucrat & other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();

        void    signForm(AForm & form);

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

        void    executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif