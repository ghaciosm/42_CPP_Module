#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *new_z = zombieHorde(N, "gulcin");

    for(int i = 0; i < N; i++)
        new_z[i].announce();
    delete [] new_z;
}