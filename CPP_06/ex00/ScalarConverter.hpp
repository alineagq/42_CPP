#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    static char toChar(const std::string &literal);
    static int toInt(const std::string &literal);
    static float toFloat(const std::string &literal);
    static double toDouble(const std::string &literal);
};

#endif // SCALARCONVERTER_HPP
