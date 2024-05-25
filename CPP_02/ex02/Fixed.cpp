#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->value = n << fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->value * other.getRawBits()) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->value << fractionalBits) / other.getRawBits());
    return result;
}

// Increment/Decrement operators
Fixed &Fixed::operator++() {
    ++this->value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++this->value;
    return temp;
}

Fixed &Fixed::operator--() {
    --this->value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --this->value;
    return temp;
}

// Min/Max static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Output stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
