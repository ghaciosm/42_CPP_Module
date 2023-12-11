#include "Span.hpp"

Span::Span(){}
Span::Span(unsigned int n) : N(n){}

Span::Span(const Span & other) : N(other.N), numbers(other.numbers)
{}

Span& Span::operator=(const Span & other)
{
    if(this != &other)
    {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span(){
}

void    Span::addNumber(int num)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Maximum elements reached");
    else
        numbers.push_back(num);
}

int     Span::shortestSpan() const
{
    if(numbers.size() < 2)
        throw std::logic_error("There are not enough numbers to find span");
    std::vector<int> sortedNum = numbers;
    std::sort(sortedNum.begin(), sortedNum.end());
    
    size_t i =2;
    int minSpan = sortedNum[1] - sortedNum[0];

    while(i < sortedNum.size())
    {
        int currentSpan = sortedNum[i] - sortedNum[i - 1];
        if(currentSpan < minSpan)
            minSpan = currentSpan;
        i++;
    }

    return minSpan;
}

int Span::longestSpan() const
{
    if(numbers.size() < 2)
        throw std::logic_error("There are not enough numbers to find span");

    std::vector<int>::const_iterator minElement = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxElement = std::max_element(numbers.begin(), numbers.end());

    return *maxElement - *minElement;
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) 
{
    while (first != last) {
        addNumber(*first);
        first++;
    }
}
