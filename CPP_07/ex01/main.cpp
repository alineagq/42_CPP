#include <iostream>
#include "iter.hpp"

void printInt(int n) {
    std::cout << n << " ";
}

void printDouble(double d) {
    std::cout << d << " ";
}

template <typename T>
void multiplyByTwo(T& value) {
    value = value * 2;
}

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    std::cout << "Test 1 - Printing integers: ";
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Test 2 - Printing doubles: ";
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArr, 4, printDouble);
    std::cout << std::endl;

    std::cout << "Test 3 - Multiplying by 2 (integers): ";
    int intArr2[] = {1, 2, 3, 4};
    iter(intArr2, 4, multiplyByTwo<int>);
    iter(intArr2, 4, printInt);
    std::cout << std::endl;

    std::cout << "Test 4 - Multiplying by 2 (doubles): ";
    double doubleArr2[] = {1.1, 2.2, 3.3};
    iter(doubleArr2, 3, multiplyByTwo<double>);
    iter(doubleArr2, 3, printDouble);
    std::cout << std::endl;

    std::cout << "Test 5 - Printing elements of a string array: ";
    const char* strArr[] = {"Hello", "World", "C++"};
    iter<const char*>(strArr, 3, printElement<const char*>);
    std::cout << std::endl;

    return 0;
}
