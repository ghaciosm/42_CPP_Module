#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie *newZombies = new Zombie[N];
    while(i< N)
    {
        newZombies[i] = Zombie(name);
        i++;
    }
    return(newZombies);
}