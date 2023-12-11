#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if(ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    BitcoinExchange bitcoinExchange;
    bitcoinExchange.readDataBase("data.csv"); // your_database.csv dosyanızın gerçek adıyla değiştirin
    bitcoinExchange.calculateValues(av[1]); // input.txt dosyanızın gerçek adıyla değiştirin

    return 0;
}
