#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate()
{
    int num = std::rand() % 3;
    if(num == 0)
        return (new A);
    else if(num == 1)
        return (new B);
    else if(num == 2)
        return (new C);
    return NULL;
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

//std::bad_cast
void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));

    Base * obje1 = generate();
    Base * obje2 = generate();
    Base * obje3 = generate();

    std::cout << "obje 1: ";
    identify(obje1);
    std::cout << "obje 2: ";
    identify(*obje2);
    std::cout << "obje 3: ";
    identify(*obje3);

    delete obje1;
    delete obje2;
    delete obje3;
}