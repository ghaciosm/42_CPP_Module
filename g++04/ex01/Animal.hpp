#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class   Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void    makeSound() const;
        std::string getType() const;
};
/*Sonuç olarak, miras alınan sınıflarda yıkıcıların sanal olması, 
polimorfizm ve temiz bellek yönetimi gibi önemli konuları ele alır. 
Sanal yıkıcılar, doğru işlevlerin çağrılmasını sağlayarak 
programın düzgün çalışmasını ve güvenliğini sağlar.*/

#endif