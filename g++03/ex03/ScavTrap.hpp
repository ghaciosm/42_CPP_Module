#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*Sanal kalıtım, taban sınıfın nesnesinin bir kez oluşturulmasını ve türetilmiş sınıfların bu nesneyi paylaşmasını sağlar*/
class ScavTrap :virtual public ClapTrap
{
    public:
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string &target);
};

#endif