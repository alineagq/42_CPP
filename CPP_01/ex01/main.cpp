#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;
    std::string name = "HordeZombie";

    // Create a horde of N zombies
    Zombie* horde = zombieHorde(N, name);
    if (horde != NULL) {
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    } else {
        std::cerr << "Failed to create zombie horde" << std::endl;
    }

    return 0;
}
