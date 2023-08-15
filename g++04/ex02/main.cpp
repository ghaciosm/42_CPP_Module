#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << std::endl;
    //AAnimal *a = new AAnimal();
    AAnimal *i = new Dog();
    AAnimal *j = new Cat();

    std::cout << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;

    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    
    std::cout << std::endl;
    delete j;
    delete i;
    
    return (0);

}