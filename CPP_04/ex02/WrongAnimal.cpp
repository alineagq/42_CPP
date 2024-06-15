#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Some wrong animal sound\n";
}

std::string WrongAnimal::getType() const {
    return type;
}
