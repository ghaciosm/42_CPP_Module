#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrav " << getName() << " created! " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrav " << getName() << " created by copying!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << getName() << " assigned copy!" << std::endl;
    }
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< getName() << " is now in Gate keeper mode!" <<std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if(getEnergyPoints() > 0 && getHitPoints() >= 0)
    {
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << "ScavTrap " << getName() << " attacks "  << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    }
}