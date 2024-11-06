#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return false;
    }

    std::string line;
    char delimiter = ',';  // Default to comma

    // Read the first line to determine the delimiter
    std::getline(file, line);
    if (line.find(",") != std::string::npos) {
        delimiter = ',';
    } else if (line.find("|") != std::string::npos) {
        delimiter = '|';
    } else {
        std::cerr << "Error: unsupported delimiter in input file.\n";
        return false;
    }

    // Read the rest of the lines
    file.seekg(0, std::ios::beg);  // Reset file pointer to the beginning
    std::getline(file, line);  // Skip the header line
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;

        // Parse using the correct delimiter
        if (delimiter == ',') {
            if (!(std::getline(iss, dateStr, ',') && std::getline(iss, valueStr, ','))) {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }
        } else if (delimiter == '|') {
            if (!(std::getline(iss, dateStr, '|') && std::getline(iss, valueStr, '|'))) {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }
        }

        if (!isValidDate(dateStr)) {
            std::cerr << "Error: invalid date format => " << dateStr << "\n";
            continue;
        }

        if (!isValidValue(valueStr)) {
            std::cerr << "Error: not a positive number => " << valueStr << "\n";
            continue;
        }

        double value;
        std::stringstream(valueStr) >> value;
        bitcoinRates[dateStr] = value;
    }

    file.close();
    return true;
}

void BitcoinExchange::processData(const std::string& inputFilename) {
    std::ifstream file(inputFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file.\n";
        return;
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

        double value;
        std::stringstream(valueStr) >> value;
        double closestRate = findClosestRate(dateStr);
        if (closestRate < 0) {
            std::cerr << "Error: no valid rate found for date => " << dateStr << "\n";
        } else {
            std::cout << dateStr << " => " << value << " = " << std::fixed << std::setprecision(2) << value * closestRate << "\n";
        }
    }
}

double BitcoinExchange::findClosestRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = bitcoinRates.lower_bound(date); 
    if (it == bitcoinRates.begin() && date < it->first) {
        return -1;
    } else if (it == bitcoinRates.end()) {
        return (--it)->second; 
    } else if (it->first == date) {
        return it->second; 
    } else {
        return (--it)->second; 
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    std::stringstream ss(value);
    double num;
    ss >> num;
    return !ss.fail() && num > 0 && num <= 1000;
}
