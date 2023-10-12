#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl;
    try
    {
        Bureaucrat bur1("HighGrade", 0);
        std::cout << bur1 << std::endl;

        Bureaucrat bur2("LowGrade", 151);
        std::cout << bur2 << std::endl;

        Bureaucrat bur3("NormalGrade", 1);
        std::cout << bur3 << std::endl;
        
        Bureaucrat bur4("NormalGrade2", 150);
        std::cout << bur4 << std::endl;

        Bureaucrat bur5("Normal", 30);
        std::cout << bur5 << std::endl;

        bur3.incrementGrade();
        std::cout << bur3 << std::endl;
        

        bur4.decrementGrade();
        std::cout << bur4 << std::endl;

        bur5.incrementGrade();
        std::cout << bur5 << std::endl;
        bur5.decrementGrade();
        std::cout << bur5 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}