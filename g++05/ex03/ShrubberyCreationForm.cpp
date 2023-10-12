#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other)
{
    target=other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    
    std::string asciiTree = "ASCII art of a tree\n"
        "   *   \n"
        "  ***  \n"
        " ***** \n"
        "*******\n"
        "  ***  \n";
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << asciiTree;
        file.close();
    }    
    else
        throw std::runtime_error("Failed to create shrubbery file");
}
