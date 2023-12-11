#include <iostream>
#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& other)
{
    (void)other;
}
RPN&  RPN::operator=(const RPN & other)
{
    (void)other;
    return *this;
}

void    RPN::calculateExpression(const std::string & expression)
{
    std::istringstream str(expression);
    std::stack<int> numberStack;

    std::string token;
    while (str >> token) 
    {
        if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            if (numberStack.size() < 2) {
                std::cerr << "ERROR" << std::endl;
                return ;
            }

            int operand2 = numberStack.top();
            numberStack.pop();
            int operand1 = numberStack.top();
            numberStack.pop();

            int result = 0;
            if (token == "+")
                result = operand1 + operand2;
            else if (token == "-")
                result = operand1 - operand2;
            else if (token == "*")
                result = operand1 * operand2;
            else if (token == "/") 
            {
                if (operand2 == 0) 
                {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return ;
                }
                result = operand1 / operand2;
            }
            numberStack.push(result);
        } 
        else 
        {
            int number = std::atoi(token.c_str());
            if ((number == 0 && token != "0") || number >= 10) 
            {
                std::cerr << "ERROR" << std::endl;
                return ;
            }
            numberStack.push(number);
        }
    }
    if (numberStack.size() < 1)
        std::cerr << "ERROR" << std::endl;
    std::cout << numberStack.top() << std::endl;
}


