#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<class T>
void    func(T &a)
{
    std::cout << a << std::endl;
}

template<typename T>
void    iter(T *array, size_t length, void (*func)(T &element) )
{
    size_t i = 0;
    while(i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif