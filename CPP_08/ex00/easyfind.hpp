#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept> // for std::exception

template <typename T>
typename T::iterator easyfind(T &container, int val) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    for (; it != ite; ++it) {
        if (*it == val) {
            return it;
        }
    }

    throw std::exception();
}

#endif // EASYFIND_HPP
