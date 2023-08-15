#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat & other)
{
    if(this != &other)
    {
        WrongAnimal::operator=(other);
        std::cout << "WrongCat copy assignment operator called!" << std::endl;
    }
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Miav! Miav!" << std::endl;
}