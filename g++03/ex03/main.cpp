#include "DiamondTrap.hpp"

int main()
{
    ClapTrap a("musab");
    ScavTrap b("gulcin");
    FragTrap c("ayse");
    DiamondTrap d("ali");
    std::cout << std::endl;

    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(6);
    std::cout << std::endl;
    b.attack("enemy");
    b.takeDamage(15);
    b.beRepaired(6);
    b.guardGate();
    std::cout << std::endl;
    c.attack("enemy");
    c.takeDamage(7);
    c.beRepaired(3);
    c.highFivesGuys();
    std::cout << std::endl;
    d.attack("enemy");
    d.takeDamage(14);
    d.beRepaired(20);
    d.whoAmI();
}