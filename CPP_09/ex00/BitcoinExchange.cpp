#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
    loadDatabase(databaseFile);
}

void BitcoinExchange::loadDatabase(const std::string &databaseFile) {
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, rateStr;
        double rate;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            std::istringstream rateStream(rateStr);
            if (rateStream >> rate || rateStr == "0") {  // Permite valor zero
                exchangeRates[date] = rate;
            }
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {
        return it->second;
    }

    // Procurar a data mais próxima abaixo
    it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.begin()) {
        --it;
        return it->second;
    }

    return 0.0; // Caso nenhuma data esteja disponível
}
