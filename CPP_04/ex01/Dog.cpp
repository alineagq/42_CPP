#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructed\n";
}

Dog& Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Dog assigned\n";
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}
