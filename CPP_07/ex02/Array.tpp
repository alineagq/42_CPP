#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : m_data(nullptr), m_size(0) {}

template<typename T>
Array<T>::Array(size_t n) : m_data(new T[n]), m_size(n) {}

template<typename T>
Array<T>::Array(const Array<T>& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        // Free existing memory
        delete[] m_data;

        // Allocate new memory
        m_size = other.m_size;
        m_data = new T[m_size];

        // Copy elements
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] m_data;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
size_t Array<T>::size() const {
    return m_size;
}

#endif // ARRAY_TPP
