#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers>\n";
        return 1;
    }

    std::vector<int> numbers;
    try {
        for (int i = 1; i < argc; ++i) {
            int num = std::stoi(argv[i]);
            if (num <= 0) {
                throw std::invalid_argument("Non-positive integer detected");
            }
            numbers.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    PmergeMe sorter(numbers);

    std::cout << "Before:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << "\n";

    auto start1 = std::chrono::high_resolution_clock::now();
    sorter.sortContainer1();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    sorter.sortContainer2();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "After:";
    for (int num : sorter.getSortedContainer1()) {
        std::cout << " " << num;
    }
    std::cout << "\n";

    std::cout << "Time to process a range of " << numbers.size() << " elements with container 1: " << duration1.count() << " us\n";
    std::cout << "Time to process a range of " << numbers.size() << " elements with container 2: " << duration2.count() << " us\n";

    return 0;
}
