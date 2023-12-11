#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> bitcoinData;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    readDataBase(const std::string & filename);
        void    calculateValues(const std::string & filename);

};

#endif