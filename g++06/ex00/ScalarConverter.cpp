#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter & other)
{
    (void)other;
    return *this;
}

bool ScalarConverter::isFinite(float value)
{
    return (value != (std::numeric_limits<float>::infinity() && value != -std::numeric_limits<float>::infinity()));
}

bool ScalarConverter::isFinite(double value)
{
    return value != std::numeric_limits<float>::infinity() && value != -std::numeric_limits<float>::infinity();
}

int   ScalarConverter::pseudo_control(const std::string &literal)
{
    if(literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
	    std::cout << "int: impossible" << std::endl;
	    std::cout << "float: " << literal << "f" <<std::endl;
	    std::cout << "double: " << literal << std::endl;
    }
    else if (literal == "nanf" || literal == "-inff" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
	    std::cout << "int: impossible" << std::endl;
	    std::cout << "float: " << literal << std::endl;
	    std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    }
    else
        return(0);
    return (1);
}

void    ScalarConverter::convert(const std::string & literal)
{
    if (ScalarConverter::pseudo_control(literal))
        return;
    
    char *endPtr;
    long longValue = std::strtol(literal.c_str(), &endPtr, 10);
    double doubleValue = std::strtod(literal.c_str(), &endPtr);
    
    std::cout << "char: ";
    if (longValue >= std::numeric_limits<char>::min() && longValue <= std::numeric_limits<char>::max()) 
    {
        char charVal = static_cast<char>(longValue);
        if (isprint(charVal))
            std::cout << "'" << charVal << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } 
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (longValue <= INT_MAX && longValue >= INT_MIN)
    {
        int intVal = static_cast<int>(longValue);
        std::cout << intVal << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (isFinite(static_cast<float>(doubleValue)))
    {
        if(static_cast<float>(longValue) == doubleValue)
        {
            float floatVal = static_cast<float>(doubleValue);
            std::cout <<  floatVal  << ".0" << "f" << std::endl;
        }
        else
        {
            float floatVal = static_cast<float>(doubleValue);
            std::cout <<  floatVal  << "f" << std::endl;
        }
    }

    std::cout << "double: ";
    if (isFinite(doubleValue))
    {
        if(static_cast<double>(longValue) == doubleValue)
        {
            std::cout <<  doubleValue  << ".0" << std::endl;
        }
        else
            std::cout <<  doubleValue  << std::endl;
    }
}