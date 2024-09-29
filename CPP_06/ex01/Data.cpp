#include "Data.hpp"

Data::Data(int v, double s) : value(v), score(s) {}

Data::Data(const Data &other) : value(other.value), score(other.score) {}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        value = other.value;
        score = other.score;
    }
    return *this;
}

Data::~Data() {}
