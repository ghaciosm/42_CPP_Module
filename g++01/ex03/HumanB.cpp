#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}
void HumanB::attack()
{
    if(!(weap.getType().empty()))
        std::cout << name << " attacks with their " << weap.getType() << std::endl;
    else
        std::cout << name << " connot attack" << std::endl;
}

void HumanB::setWeapon(Weapon weap)
{
    this->weap = weap;
}