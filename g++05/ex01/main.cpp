#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try 
    {
        std::cout << std::endl;
        Bureaucrat bureaucrat1("John", 5);
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Alice", 120);
        std::cout << bureaucrat2 << std::endl;

        Form form1("Form1", 10, 30);
        std::cout << form1 << std::endl;

        Form form2("Form2", 2, 80);
        std::cout << form2 << std::endl;

        bureaucrat1.signForm(form1);
        std::cout << form1 << std::endl;

        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}