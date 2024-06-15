#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
    void checkSize();
};

#endif // SPAN_HPP
