#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Complaining at DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Complaining at INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Complaining at WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Complaining at ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Complaining at an unknown level:" << std::endl;
    harl.complain("UNKNOWN");
    std::cout << std::endl;

    return 0;
}
