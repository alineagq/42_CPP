#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate() {
    int random = std::rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr; // Should not happen due to modulo operation
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Object identified as A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Object identified as B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Object identified as C" << std::endl;
    } else {
        std::cout << "Unknown object type" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Base* objectPtr = generate();
    identify(objectPtr);

    Base& objectRef = *objectPtr;
    identify(objectRef);

    delete objectPtr;

    return 0;
}
