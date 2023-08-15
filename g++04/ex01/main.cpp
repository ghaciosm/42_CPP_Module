#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    
    std::cout << std::endl;
    Animal* animals[6];//Animal türünde işaretçileri tutacak bir dizi oluşturuyor
    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
    }
    std::cout << std::endl;

    for (int i = 3; i < 6; ++i) {
        animals[i] = new Cat();
    }
    std::cout << std::endl;

    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }

    std::cout << std::endl;

}