#include <iostream>
#include "Array.hpp"

int main() 
{

    int i = -1;
    Array<int> intArray(5);
    while (++i < intArray.size()) 
        intArray[i] = i * 2;

    i = -1;
    std::cout << "Int Array: " << std::endl;
    while (++i < intArray.size())
        std::cout << "i: " << intArray[i] << std::endl;

    try 
    {
        intArray[6] = 10; // Should throw an exception
        std::cout << "4. " << intArray[4] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;
    doubleArray[2] = 1.618;

    i = -1;
    std::cout << "Double Array: " << std::endl;
    while(++i < doubleArray.size())
        std::cout << "i: "<<doubleArray[i] << std::endl;
    return 0;
}
