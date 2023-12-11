#include <vector>
#include <list>
#include <set>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int main() 
{
    // Vector example
    std::vector<int> vec;
    int i = 1;
    while (i <= 5) {
        vec.push_back(i);
        ++i;
    }
    try 
    {
        int result = easyfind(vec, 3);
        std::cout << "Vector - Element found: " << result << std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Vector - Element not found" << std::endl;
    }

    // List example
    std::list<int> lst;
    i = 10;
    while (i <= 50) {
        lst.push_back(i);
        i += 10;
    }
    try
    {
        int result = easyfind(lst, 70);
        std::cout << "List - Element found: " << result << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "List - Element not found" << std::endl;
    }

    // Deque example
    std::deque<int> deq;
    i = 1000;
    while (i <= 5000) {
        deq.push_back(i);
        deq.push_front(i + 1);
        i += 1000;
    }
    try {
        int result = easyfind(deq, 6000);
        std::cout << "Deque - Element found: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Deque - Element not found" << std::endl;
    }

    return 0;
}
