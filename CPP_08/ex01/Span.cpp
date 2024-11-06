#include "Span.hpp"
#include <algorithm> // for std::sort, std::minmax_element
#include <stdexcept> // for std::runtime_error
#include <limits>    // for std::numeric_limits

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N); // Pre-allocating capacity
}

void Span::addNumber(int number) {
    checkSize(); // Ensure capacity before adding
    _numbers.push_back(number);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Cannot find shortest span with less than 2 elements");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (std::vector<int>::size_type i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Cannot find longest span with less than 2 elements");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    
    return maxVal - minVal;
}


void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>::size_type rangeSize = std::distance(begin, end);
    if (_numbers.size() + rangeSize > _maxSize)
        throw std::runtime_error("Adding range would exceed Span's capacity");
    
    _numbers.insert(_numbers.end(), begin, end);
}

void Span::checkSize() {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
}
