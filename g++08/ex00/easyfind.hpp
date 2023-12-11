#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T & container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if(it != container.end())
        return (*it);
    else
        throw std::out_of_range("Element not found");
}

#endif