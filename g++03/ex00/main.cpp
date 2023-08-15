#include "ClapTrap.hpp"

int main()
{
    std::cout << std::endl;
    ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2("ClapTrap2");

    clapTrap1.attack("Enemy");
    clapTrap2.takeDamage(5);
    clapTrap1.beRepaired(3);

    return 0;
}