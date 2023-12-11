#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) : bitcoinData(other.bitcoinData){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
        bitcoinData = other.bitcoinData;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

bool isValidDateFormat(const std::string &date) 
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int i = 0;
    while (i < 10) 
    {
        if (!(i == 4 || i == 7) && !isdigit(date[i]))
            return false;
        i++;
    }
    return true;
}

bool isValidValueFormat(double value)
{
    if(value < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if(value > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void    BitcoinExchange::readDataBase(const std::string & name)
{
    std::ifstream file(name.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit (0);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream str(line); 
        std::string date;
        double value;

        std::getline(str, date, ',') >> value;
        bitcoinData[date] = value;
    }
    file.close();
}

void    BitcoinExchange::calculateValues(const std::string & filename)
{
    std::ifstream inputFile(filename.c_str());
    if(!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit (0);
    }

    std::string line;
    std::getline(inputFile, line);
    while(std::getline(inputFile, line))
    {
        std::istringstream str(line);
        std::string date;
        double value;

        if(!(std::getline(str, date, '|') >> value))
        {
            std::cerr << "Error: bad input  => " << line << std::endl;
            continue;
        }
        std::string::iterator strIt = date.end();
        while (strIt != date.begin()) {
            if(std::isspace(*(strIt)))
            {
                date.erase(strIt);
                break;
            }
            --strIt;
        }
        if(!isValidDateFormat(date))
        {
            std::cerr << "Error: bad input  => " << line <<std::endl;
            continue;
        }
        if(!isValidValueFormat(value))
            continue;

        std::map<std::string, double>::iterator it = bitcoinData.lower_bound(date);

        if (it == bitcoinData.end() && it == bitcoinData.begin()) 
        {
            std::cerr << "No valid date in the database." << std::endl;
            continue;

        } 
        else if (it == bitcoinData.end())
            --it;
        else if (it != bitcoinData.begin() && it->first > date)
            --it;
        
        double result = value * it->second;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    inputFile.close();
}