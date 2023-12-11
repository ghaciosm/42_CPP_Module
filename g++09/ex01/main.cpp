#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "ARGUMAN ERROR" << std::endl;
        return 1;
    }

    RPN::calculateExpression(av[1]);
}