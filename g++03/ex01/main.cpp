#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << std::endl;
    ScavTrap scav("Gulcin");
    ClapTrap clap("Musab");

    scav.attack("Enemy");
    clap.attack("Enemy");
    scav.takeDamage(5);
    scav.beRepaired(3);
    clap.takeDamage(4);
    clap.takeDamage(6);
    scav.guardGate();
}