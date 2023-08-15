#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
    {
        type = other.type;
        std::cout << "WrongAnimal copy assignment operator called!" << std::endl;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!" <<std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type);
}