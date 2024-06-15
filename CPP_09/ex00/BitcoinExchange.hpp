#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <vector>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    bool loadData(const std::string& filename);
    void processData();

private:
    struct PriceData {
        std::string date;
        double value;
    };

    std::vector<PriceData> prices;
    std::map<std::string, double> bitcoinRates; // Map to store bitcoin rates by date

    double findClosestRate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
};

#endif // BITCOIN_EXCHANGE_HPP
