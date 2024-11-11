#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

// Função para validar a data no formato YYYY-MM-DD
bool isValidDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Verificação de dias por mês (sem considerar anos bissextos)
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2 && day > 28) return false;

    return true;
}

// Função para parsear a linha de entrada e extrair a data e o valor
bool parseInputLine(const std::string &line, std::string &date, double &value) {
    std::istringstream ss(line);

    // Extrair a data e validar
    if (!(ss >> date) || !isValidDate(date)) {
        std::cerr << "Error: invalid date format => " << date << std::endl;
        return false;
    }

    // Ignorar caracteres até encontrar um número válido
    std::string valueStr;
    while (ss >> valueStr) {
        // Verificar se é um número válido (inteiro ou float)
        std::istringstream valueStream(valueStr);
        if ((valueStream >> value) && value >= 0.0 && value <= 1000.0) {
            return true;
        }
    }

    std::cerr << "Error: invalid value format => " << line << std::endl;
    return false;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: program requires a single input file as argument." << std::endl;
        return 1;
    }

    BitcoinExchange exchange("bitcoin_database.csv"); // Nome do arquivo CSV do banco de dados
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(inputFile, line)) {
        if (isFirstLine) { // Pular a primeira linha do cabeçalho
            isFirstLine = false;
            continue;
        }

        std::string date;
        double value;

        if (!parseInputLine(line, date, value)) {
            std::cerr << "Error: bad input format => " << line << std::endl;
            continue;
        }

        double exchangeRate = exchange.getExchangeRate(date);
        double result = value * exchangeRate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    return 0;
}
