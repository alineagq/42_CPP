#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* animal = new Animal();
    const Animal* caramel = new Dog();
    const Animal* pawers = new Cat();
    std::cout << caramel->getType() << " " << std::endl;
    std::cout << pawers->getType() << " " << std::endl;
    pawers->makeSound();
    caramel->makeSound();
    animal->makeSound();

    delete animal;
    delete caramel;
    delete pawers;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongpaw = new WrongCat();
    std::cout << wrongpaw->getType() << " " << std::endl;
    wrongpaw->makeSound();
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongpaw;

    return 0;
}
