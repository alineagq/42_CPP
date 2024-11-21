#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int length;

public:
    Array() : elements(NULL), length(0) {}

    Array(unsigned int n) : elements(new T[n]()), length(n) {}

    Array(const Array& other) : elements(NULL), length(0) {
        *this = other;
    }

    ~Array() {
        delete[] elements;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            length = other.length;
            elements = new T[length];
            for (unsigned int i = 0; i < length; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    unsigned int size() const {
        return length;
    }
};

#endif
