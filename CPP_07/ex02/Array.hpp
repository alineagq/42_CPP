#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // for size_t
#include <stdexcept> // for std::out_of_range

template<typename T>
class Array {
private:
    T* m_data;
    size_t m_size;

public:
    // Default constructor
    Array();

    // Parameterized constructor
    explicit Array(size_t n);

    // Copy constructor
    Array(const Array<T>& other);

    // Assignment operator
    Array<T>& operator=(const Array<T>& other);

    // Destructor
    ~Array();

    // Subscript operator
    T& operator[](size_t index);

    // Const subscript operator
    const T& operator[](size_t index) const;

    // Member function to get the size
    size_t size() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
