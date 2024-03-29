#include "Zombie.hpp"


Zombie::Zombie(const std::string& name) : name_(name) {
  std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : Zombie("") {}

Zombie::~Zombie() {
  std::cout << name_ << " is dead." << std::endl;
}

void Zombie::announce(void) const {
  std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(const std::string& name) {
  Zombie* zombie = new Zombie(name);
  return zombie;
}

void randomChump(const std::string& name) {
  Zombie zombie(name);
  zombie.announce();
}
