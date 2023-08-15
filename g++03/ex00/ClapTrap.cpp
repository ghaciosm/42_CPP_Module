#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Default constructor called!!!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << this->name <<" constructor called!!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called!!!" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called!!!" << std::endl;
    if(this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << name <<" destructor called!!!" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if(energyPoints > 0 && hitPoints >= 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks "  << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap" << name << " could not be attack!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
    }
    else
        std::cout << "ClapTrap" << name << " does not have enough hit points to take damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(energyPoints > 0 && hitPoints >= 0)
    {
        std::cout << "ClapTrap " << name << " is repaired and gains " << amount << " hit points!" << std::endl;
        energyPoints--;
        hitPoints += amount;
    }
    else
        std::cout << "ClapTrap " << name << " could not be repaired!!!" << std::endl;
}