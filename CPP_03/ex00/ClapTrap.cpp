#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << this->name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << this->name << " assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " can't attack. No hit points or energy points left." << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
        return;
    }
    this->hitPoints -= amount;
    if (this->hitPoints < 0) {
        this->hitPoints = 0;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " can't be repaired. No hit points or energy points left." << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
}

const std::string &ClapTrap::getName() const {
    return this->name;
}

int ClapTrap::getHitPoints() const {
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return this->attackDamage;
}
