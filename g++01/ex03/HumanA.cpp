#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon) : weap(weapon)
{
    this->name = name;
}

void    HumanA::attack()
{
    std::cout << this->name <<" attacks with their " << weap.getType() << std::endl; 
}