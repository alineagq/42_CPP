#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("ClapTrap");

    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("target");

    ClapTrap copy(clap);
    ClapTrap assigned("Assigned");
    assigned = clap;

    return 0;
}
