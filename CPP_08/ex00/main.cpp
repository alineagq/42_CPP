#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    try {
        auto result = easyfind(vec, 3);
        std::cout << "Found value: " << *result << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found!" << std::endl;
    }

    try {
        auto result = easyfind(vec, 10);
        std::cout << "Found value: " << *result << std::endl; // This won't execute due to exception
    } catch (std::exception &e) {
        std::cout << "Value not found!" << std::endl; // This will be executed
    }

    return 0;
}
