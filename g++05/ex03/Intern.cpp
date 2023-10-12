#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern & Intern::operator=(const Intern & other)
{
    (void)other;
    return (*this);
}

int	formType(std::string name)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i = 0;
	while (i < 3)
	{
		if (name == types[i])
			return i;
		i++;
	}
	return (-1);
}

AForm    *Intern::makeForm(const std::string &formName, const std::string & target)
{
	switch(formType(formName))
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		case -1:
			std::cout << "Intern does not create " << formName << std::endl;
	}
	return NULL;
}