#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
    int value;
    double score;

    Data(int v, double s) : value(v), score(s) {}
    Data(const Data &other) : value(other.value), score(other.score) {}
    Data &operator=(const Data &other)
    {
        if (this != &other)
        {
            value = other.value;
            score = other.score;
        }
        return *this;
    }
    ~Data() {}

};

#endif
