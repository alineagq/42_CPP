#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string &databaseFile);
    double getExchangeRate(const std::string &date) const;

private:
    std::map<std::string, double> exchangeRates;
    void loadDatabase(const std::string &databaseFile);
};

#endif
