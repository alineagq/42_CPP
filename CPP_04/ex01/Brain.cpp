#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructed\n";
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructed\n";
    *this = other;
}

Brain& Brain::operator=(const Brain &other) {
    std::cout << "Brain assigned\n";
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructed\n";
}
