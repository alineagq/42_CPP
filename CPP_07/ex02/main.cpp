#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 2;
    }

    try {
        for (unsigned int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << arr[5] << std::endl; // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Array<int> arr2 = arr;

    for (unsigned int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
