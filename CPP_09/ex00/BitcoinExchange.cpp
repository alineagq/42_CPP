#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (!(iss >> dateStr >> valueStr)) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        if (!isValidDate(dateStr)) {
            std::cerr << "Error: invalid date format => " << dateStr << "\n";
            continue;
        }

        if (!isValidValue(valueStr)) {
            std::cerr << "Error: not a positive number => " << valueStr << "\n";
            continue;
        }

        double value = std::stod(valueStr);
        bitcoinRates[dateStr] = value;
    }

    file.close();
    return true;
}

void BitcoinExchange::processData() {
    for (const auto& rate : bitcoinRates) {
        double closestRate = findClosestRate(rate.first);
        if (closestRate < 0) {
            std::cerr << "Error: no valid rate found for date => " << rate.first << "\n";
        } else {
            std::cout << rate.first << " => " << rate.second << " = " << std::fixed << std::setprecision(2) << rate.second * closestRate << "\n";
        }
    }
}

double BitcoinExchange::findClosestRate(const std::string& date) const {
    auto it = bitcoinRates.lower_bound(date); // Find first rate on or after date
    if (it == bitcoinRates.begin() && date < it->first) {
        return -1; // No valid rate found
    } else if (it == bitcoinRates.end()) {
        return bitcoinRates.rbegin()->second; // Closest rate is the last one
    } else if (it->first == date) {
        return it->second; // Exact match found
    } else {
        double closestRate = (--it)->second;
        return closestRate; // Closest rate found
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Basic check for date format (YYYY-MM-DD)
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    // Additional checks for valid month and day values can be added here if necessary
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    try {
        double num = std::stod(value);
        return num > 0 && num <= 1000;
    } catch (const std::exception& e) {
        return false;
    }
}
