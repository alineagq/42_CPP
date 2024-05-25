#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << this->name << " assigned." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0) {
        std::cout << "ScavTrap " << this->name << " can't attack. No hit points or energy points left." << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
}
