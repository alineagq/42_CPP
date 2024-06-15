#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];

    try
    {
        ScalarConverter::convert(literal);
    }
    catch (const std::invalid_argument &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
