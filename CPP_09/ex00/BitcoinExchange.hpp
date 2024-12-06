#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

/*****************************************
    Date class implementation
*****************************************/


class Date {
private:
    int year;
    int month;
    int day;

public:
    Date();
    explicit Date(const std::string& dateStr);
    Date(const Date& other);
    Date& operator=(const Date& other);
    ~Date();

    bool parse(const std::string& dateStr);
    bool validate() const;
    std::string toString() const;

    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

/*****************************************
    BitcoinExchange class implementation
*****************************************/

class BitcoinExchange {
private:
    std::map<Date, double> exchangeRates;

public:
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadDatabase(const std::string& databaseFile);
    double getExchangeRate(const std::string& date) const;
};

#endif
