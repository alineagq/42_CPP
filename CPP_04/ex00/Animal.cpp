#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed\n";
}

Animal::~Animal() {
    std::cout << "Animal destructed\n";
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound\n";
}

std::string Animal::getType() const {
    return type;
}
