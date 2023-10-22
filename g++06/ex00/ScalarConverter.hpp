#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
#include <climits>
#include <string>
#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

        static void convert(const std::string& literal);

        static int pseudo_control(const std::string &literal);
        static bool isFinite(float value);
        static bool isFinite(double value);
};

#endif