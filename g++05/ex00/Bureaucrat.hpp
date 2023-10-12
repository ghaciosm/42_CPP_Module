#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
//throw() = noexcept
//Specifies that it will not throw an exception under any circumstances

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif