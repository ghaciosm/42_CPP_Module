#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl;
    Intern someRandomIntern;
    AForm* rrf = NULL;

    try 
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (!rrf) 
            std::cerr << "Form creation error" << std::endl;
        else
        { 
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}