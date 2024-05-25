#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << this->name << " copy constructed.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << this->name << " assigned.\n";
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destructed.\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " requests high fives!\n";
}
