#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)//constructor
{
    this->name = name;
}

Zombie::~Zombie()//destructor
{
    std::cout << this->name << " destroyed..." << std::endl;
}
