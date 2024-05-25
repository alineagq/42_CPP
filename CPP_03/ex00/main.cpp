#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("ClapTrap");

    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Testing boundary conditions
    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("target");

    // Additional test cases
    ClapTrap copy(clap);
    ClapTrap assigned("Assigned");
    assigned = clap;

    return 0;
}
