#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
class AMateria; // öncedenbildirim

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0; //karakterin adını döndüren saf sanal fonksiyon
        virtual void equip(AMateria* m) = 0;// materyali karaktere ekliyor
        virtual void unequip(int idx) = 0;// belirtilen indexteki materyali karakterden çıkarıyo
        virtual void use(int idx, ICharacter& target) = 0;//belirtilen indexteki materyali kullanarak hedefte değişiklik yapıyo
};

# include "AMateria.hpp"

#endif