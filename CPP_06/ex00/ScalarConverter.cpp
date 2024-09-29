#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
    // Convert to char
    try {
        char charValue = toChar(literal);
        std::cout << "char: ";
        if (std::isprint(static_cast<unsigned char>(charValue)))
            std::cout << "'" << charValue << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "char: impossible" << std::endl;
    }

    // Convert to int
    try {
        int intValue = toInt(literal);
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::exception &e) {
        std::cout << "int: impossible" << std::endl;
    }

    // Convert to float
    try {
        float floatValue = toFloat(literal);
        std::cout << "float: ";
        if (std::isnan(floatValue) || std::isinf(floatValue))
            std::cout << floatValue << "f" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "float: impossible" << std::endl;
    }

    // Convert to double
    try {
        double doubleValue = toDouble(literal);
        std::cout << "double: ";
        if (std::isnan(doubleValue) || std::isinf(doubleValue))
            std::cout << doubleValue << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    } catch (const std::exception &e) {
        std::cout << "double: impossible" << std::endl;
    }
}

char ScalarConverter::toChar(const std::string &literal)
{
    try {
        int intValue = toInt(literal);
        if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
            return static_cast<char>(intValue);
        else
            throw std::invalid_argument("Invalid char literal");
    } catch (...) {
        throw std::invalid_argument("Invalid char literal");
    }
}

int ScalarConverter::toInt(const std::string &literal)
{
    std::stringstream ss(literal);
    int value;
    if (!(ss >> value))
        throw std::invalid_argument("Invalid int literal");
    return static_cast<int>(value); // Explicit static_cast to int
}

float ScalarConverter::toFloat(const std::string &literal)
{
    std::stringstream ss(literal);
    float value;
    if (!(ss >> value))
        throw std::invalid_argument("Invalid float literal");
    return static_cast<float>(value);
}

double ScalarConverter::toDouble(const std::string &literal)
{
    std::stringstream ss(literal);
    double value;
    if (!(ss >> value))
        throw std::invalid_argument("Invalid double literal");
    return static_cast<double>(value);
}
