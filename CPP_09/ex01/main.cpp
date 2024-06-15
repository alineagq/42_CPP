#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"RPN_expression\"\n";
        return 1;
    }

    std::string expression = argv[1];
    RPN rpnCalculator;

    try {
        double result = rpnCalculator.evaluate(expression);
        std::cout << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
