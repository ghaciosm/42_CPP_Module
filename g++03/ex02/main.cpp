#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    ClapTrap clap("gulcin");
    clap.attack("enemy");
    clap.beRepaired(3);
    clap.takeDamage(7);

    ScavTrap scav("musab");
    scav.attack("enemy");
    scav.takeDamage(15);
    scav.beRepaired(5);
    scav.guardGate();

    FragTrap frag("eerr");
    frag.attack("enemy");
    frag.takeDamage(5);
    frag.beRepaired(1);
    frag.highFivesGuys();


}
