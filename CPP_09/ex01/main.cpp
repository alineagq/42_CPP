#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments." << std::endl;
        return 1;
    }

    try {
        RPN rpn(argv[1]);
        rpn.evaluate();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
