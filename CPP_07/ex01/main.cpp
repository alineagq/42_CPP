#include <iostream>
#include "iter.hpp"

void printInt(int& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    x += 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array before increment: ";
    iter(arr, length, printInt);
    std::cout << std::endl;

    iter(arr, length, increment);

    std::cout << "Array after increment: ";
    iter(arr, length, printInt);
    std::cout << std::endl;

    return 0;
}
