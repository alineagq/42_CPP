#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    BitcoinExchange bitcoinExchange;

    if (!bitcoinExchange.loadData(inputFile)) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    bitcoinExchange.processData();

    return 0;
}
