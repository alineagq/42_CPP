#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("ClapTrap");
    ScavTrap scav("ScavTrap");

    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("target");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    // Testing boundary conditions
    scav.takeDamage(100);
    scav.beRepaired(5);
    scav.attack("target");

    // Additional test cases
    ScavTrap copy(scav);
    ScavTrap assigned("Assigned");
    assigned = scav;

    return 0;
}
