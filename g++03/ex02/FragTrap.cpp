#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FlagTrap " << getName() << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FlagTrap " << getName() << " created by copying!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << getName() << " assigned copy!" <<std::endl;
    }
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " destroyed!" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    if(getHitPoints() > 0 && getEnergyPoints() >= 0)
    {
        std::cout << "High Fives:)" << std::endl;
    }
}
