#include <iostream>
#include "iter.hpp"

// Example function templates to be used with iter
template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

template <typename T>
void squareElement(T &element) {
    element *= element;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Printing intArray:" << std::endl;
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Printing doubleArray:" << std::endl;
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    std::cout << "Printing charArray:" << std::endl;
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    std::cout << "Squaring elements in intArray:" << std::endl;
    iter(intArray, 5, squareElement<int>);
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    return 0;
}
