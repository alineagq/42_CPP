#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    // Typedefs for iterators
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Iterator support functions
    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }

    const_iterator begin() const { return std::stack<T>::c.begin(); }
    const_iterator end() const { return std::stack<T>::c.end(); }
};

#endif // MUTANTSTACK_HPP
