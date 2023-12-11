#include "Span.hpp"

int main() {
    try
    {
        Span sp = Span(15000);

        std::vector<int> vec;
        int i= 1;
        while (i <= 15000) {
            vec.push_back(i);
            i++;
        }

        // Adding the range of numbers to the Span
        sp.addRange(vec.begin(), vec.end());

        // Finding the shortest and longest spans
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

/*
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}*/