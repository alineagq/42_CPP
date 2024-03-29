#include "Zombie.hpp"

int main() {
  Zombie* heapZombie = newZombie("Bob");
  heapZombie->announce();

  randomChump("Alice");

  delete heapZombie;

  return 0;
}
