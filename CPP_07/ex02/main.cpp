#include <iostream>
#include <stdexcept>
#include "Array.hpp"

int main() {
    try {
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;
        arr2[0] = 10;
        std::cout << "arr2[0] = " << arr2[0] << std::endl;

        try {
            std::cout << arr2[10] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Array<int> arr3 = arr2;
        std::cout << "Size of arr3: " << arr3.size() << std::endl;
        std::cout << "arr3[0] = " << arr3[0] << std::endl;

        Array<int> arr4(3);
        arr4 = arr2;
        std::cout << "Size of arr4: " << arr4.size() << std::endl;
        std::cout << "arr4[0] = " << arr4[0] << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
