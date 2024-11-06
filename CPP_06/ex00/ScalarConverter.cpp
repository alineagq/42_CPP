#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    double value;
    
    if (std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    } else {
        value = std::strtod(literal.c_str(), NULL);
    }

    convertToChar(value);
    convertToInt(value);
    convertToFloat(value);
    convertToDouble(value);
}

void ScalarConverter::convertToChar(double value) {
    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::convertToInt(double value) {
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::convertToFloat(double value) {
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::convertToDouble(double value) {
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}
