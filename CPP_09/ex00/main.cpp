#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>

#define DB_FILE "data.csv"

std::string trim(const std::string& str) {
    std::string result = str;

    size_t start = result.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) {
        return "";
    }
    result = result.substr(start);

    size_t end = result.find_last_not_of(" \t\n\r\f\v");
    result = result.substr(0, end + 1);

    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::cout << "Argv[1]: " << argv[1] << std::endl;

    BitcoinExchange exchange(DB_FILE);

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty()) {
            continue;
        }

        std::string dateStr, rateStr;
        double rate, bitcoinAmount;

        size_t delimiter_pos = line.find(" | ");
        if (delimiter_pos == std::string::npos) {
            std::cerr << "Error: invalid file format (missing delimiter)." << std::endl;
            continue;
        }

        dateStr = line.substr(0, delimiter_pos);
        line.erase(0, delimiter_pos + 3);

        std::istringstream rateStream(line);
        if (!(rateStream >> bitcoinAmount) || bitcoinAmount <= 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (bitcoinAmount > 1000) {
            std::cerr << "Error: too large a number" << std::endl;
            continue;
        }

        rate = exchange.getExchangeRate(dateStr);

        if (rate > 0) {
            double total = rate * bitcoinAmount;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << dateStr << " => " << bitcoinAmount << " = " << total << std::endl;
        } else {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
        }
    }

    return 0;
}
