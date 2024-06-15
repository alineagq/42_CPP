#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    Span sp = Span(5);

    // Adding numbers one by one
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    // Testing shortestSpan and longestSpan
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // Adding a range of numbers
    std::vector<int> numbersToAdd = {1, 5, 8, 2};
    sp.addRange(numbersToAdd.begin(), numbersToAdd.end());

    // Testing again after adding more numbers
    std::cout << "Shortest span after range addition: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span after range addition: " << sp.longestSpan() << std::endl;

    return 0;
}
