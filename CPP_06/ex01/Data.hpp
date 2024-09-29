#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
    int value;
    double score;

    Data(int v, double s);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};

#endif
