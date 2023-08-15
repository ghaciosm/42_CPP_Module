#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class   AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
        virtual ~AAnimal();

        virtual void    makeSound() const = 0; // pure virtual function
        std::string getType() const;
};
/*Sonuç olarak, miras alınan sınıflarda yıkıcıların sanal olması, 
polimorfizm ve temiz bellek yönetimi gibi önemli konuları ele alır. 
Sanal yıkıcılar, doğru işlevlerin çağrılmasını sağlayarak 
programın düzgün çalışmasını ve güvenliğini sağlar.*/

#endif