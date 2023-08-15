#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
class HumanA
{
    private:
        std::string name;
        Weapon      &weap;
    public:
        HumanA( std::string name, Weapon &weap);
        void    attack();
    
};

#endif