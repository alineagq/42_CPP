#include "Zombie.hpp"

#include <iostream>

Zombie* zombieHorde(int N, const std::string& name) {
  Zombie* horde = new Zombie[N];

  for (int i = 0; i < N; ++i)
    horde[i].name_ = name;

  return horde;
}
