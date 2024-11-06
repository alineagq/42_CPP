#include <iostream>
#include "Span.hpp"

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Additional test for addRange with 10,000 numbers
    Span bigSpan(10000);
    std::vector<int> largeSet(10000);
    for (int i = 0; i < 10000; ++i) {
        largeSet[i] = i;
    }
    bigSpan.addRange(largeSet.begin(), largeSet.end());

    std::cout << "Shortest Span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span in bigSpan: " << bigSpan.longestSpan() << std::endl;

    return 0;
}
