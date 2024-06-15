#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("target");
        PresidentialPardonForm pardon("Alice");

        bob.signForm(shrub);
        bob.executeForm(shrub);

        bob.signForm(robo);
        bob.executeForm(robo);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
