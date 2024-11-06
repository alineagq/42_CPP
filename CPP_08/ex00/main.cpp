#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test with a vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Value not found in vector." << std::endl;
    }

    // Test with a list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found value 25 at position: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Value not found in list." << std::endl;
    }

    return 0;
}
