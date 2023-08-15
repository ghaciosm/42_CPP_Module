#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("gulcin");
    Zombie *zombie2 = newZombie("musab");
    zombie1->announce();
    zombie2->announce();
    randomChump("eerr");
    delete(zombie1);
    delete(zombie2);
}