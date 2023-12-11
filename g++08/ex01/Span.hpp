#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int>  numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span & other);
        Span& operator=(const Span & other);
        ~Span();

        void    addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
};


#endif