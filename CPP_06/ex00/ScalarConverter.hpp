#pragma once
#include <iostream>
#include <string>

class ScalarConverter {
public:
    // Static method to convert the scalar value
    static void convert(const std::string& literal);

private:
    // Private constructor to prevent instantiation
    ScalarConverter();

    // Helper methods for conversion
    static void convertToChar(double value);
    static void convertToInt(double value);
    static void convertToFloat(double value);
    static void convertToDouble(double value);
};