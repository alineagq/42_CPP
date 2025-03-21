#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    try {
        RPN rpn(argv[1]);
        rpn.evaluate();
    } catch (...) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    return 0;
}