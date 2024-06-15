#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N); // Reserve memory for N elements
}

void Span::addNumber(int number) {
    checkSize();
    _numbers.push_back(number);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::runtime_error("Cannot find shortest span with less than 2 elements");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
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

    auto minmax = std::minmax_element(_numbers.begin(), _numbers.end());
    return *minmax.second - *minmax.first;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    checkSize();
    _numbers.insert(_numbers.end(), begin, end);
    checkSize();
}

void Span::checkSize() {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
}
