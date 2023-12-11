#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN & other);
        ~RPN();

        static void calculateExpression(const std::string & expression);
};

#endif