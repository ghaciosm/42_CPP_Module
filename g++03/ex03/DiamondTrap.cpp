#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),ScavTrap(name), FragTrap(name)
{
    this->name = name;
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << name << " created!" << std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap " << name << " created by copying!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if(this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name =  other.name;
         std::cout << "DiamondTrap " << name << " assigned copy!" <<std::endl;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}