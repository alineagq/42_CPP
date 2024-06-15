#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const AAnimal* animals[10];
    
    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
    }

    for (int i = 5; i < 10; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; ++i) {
        delete animals[i];
    }

    // Test deep copy
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    return 0;
}
