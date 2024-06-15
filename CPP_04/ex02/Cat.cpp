#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat &other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructed\n";
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Cat assigned\n";
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
