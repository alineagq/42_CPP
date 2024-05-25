#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copy constructed.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned.\n";
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destructed.\n";
}

void ClapTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!\n";
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " cannot repair!\n";
    }
}
