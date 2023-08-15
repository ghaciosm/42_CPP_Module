#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    
    std::cout << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    meta->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    std::cout << std::endl;
    delete j;
    delete i;
    delete meta;
    

    std::cout << "------------- WRONG -------------" << std::endl;
    std::cout << std::endl;

    const WrongAnimal* wrongI = new WrongCat();
    const WrongAnimal* wrongJ = new WrongAnimal();
    std::cout << std::endl;

    wrongI->makeSound(); // Output: WrongAnimal sound!
    wrongJ->makeSound();

    std::cout << std::endl;
    delete wrongI;
    delete wrongJ;
    std::cout << std::endl;

}