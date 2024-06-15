#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

void ScalarConverter::convert(const std::string &literal)
{
    char charValue = toChar(literal);
    int intValue = toInt(literal);
    float floatValue = toFloat(literal);
    double doubleValue = toDouble(literal);

    std::cout << "char: ";
    if (std::isprint(charValue))
        std::cout << "'" << charValue << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (intValue == std::numeric_limits<int>::min() || intValue == std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << intValue << std::endl;

    std::cout << "float: ";
    if (std::isnan(floatValue) || std::isinf(floatValue))
        std::cout << floatValue << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(doubleValue) || std::isinf(doubleValue))
        std::cout << doubleValue << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

char ScalarConverter::toChar(const std::string &literal)
{
    if (literal.length() == 1)
        return literal[0];
    else
        throw std::invalid_argument("Invalid char literal");
}

int ScalarConverter::toInt(const std::string &literal)
{
    try
    {
        return std::stoi(literal);
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid int literal");
    }
}

float ScalarConverter::toFloat(const std::string &literal)
{
    try
    {
        return std::stof(literal);
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid float literal");
    }
}

double ScalarConverter::toDouble(const std::string &literal)
{
    try
    {
        return std::stod(literal);
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid double literal");
    }
}
