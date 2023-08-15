#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Argument error!!!" << std::endl;
        return(-1);
    }
    std::string log = av[1];
    Harl obj;
    obj.complain(log);
}