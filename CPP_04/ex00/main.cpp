#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the generic animal sound

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound(); // will output the wrong animal sound
    wrongMeta->makeSound(); // will output the wrong animal sound

    delete wrongMeta;
    delete wrongI;

    return 0;
}
