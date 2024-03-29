#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
  Zombie(const std::string& name = ""); 
  ~Zombie();

  void announce(void) const;

private:
  std::string name_;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif
