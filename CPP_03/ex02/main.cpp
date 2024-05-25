#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    clap.attack("target1");
    scav.attack("target2");
    frag.attack("target3");

    clap.takeDamage(5);
    scav.takeDamage(15);
    frag.takeDamage(25);

    clap.beRepaired(3);
    scav.beRepaired(10);
    frag.beRepaired(20);

    scav.guardGate();
    frag.highFivesGuys();

    return 0;
}
