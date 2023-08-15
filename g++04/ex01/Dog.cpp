#include "Dog.hpp"

Dog::Dog()
{ 
    this->brain = new Brain();
    type = "Dog";
    std::cout << "Dog constructor called!" << std::endl;
}
//brain = new Brain(*(other.brain));: 
//İki ayrı Brain nesnesi oluşturulur, her biri farklı bellek alanına sahip olur.
Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*(other.brain));
    std::cout << "Dog copy constructor called!" << std::endl;
}

/*Bu, kopyalama yapılırken önce mevcut brain nesnesini bellekten silip,
sonra other nesnesinin brain nesnesinin derin kopyasını oluşturuyoruz.
Bu, eski bellek alanının serbest bırakılmasını ve 
verilerin derin kopyalanmasını sağlar.
*/
Dog &Dog::operator=(const Dog & other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*(other.brain));
        std::cout << "Dog copy assignment operator called!" << std::endl;
    }
    return(*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called!" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Hav! Hav!" << std::endl;
}