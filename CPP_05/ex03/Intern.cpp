#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other; // Unused
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other; // Unused
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *form = createForm(formName, target);

    if (form)
        std::cout << "Intern creates " << formName << std::endl;
    else
        std::cout << "Error: Form " << formName << " creation failed." << std::endl;

    return form;
}

AForm *Intern::createForm(const std::string &formName, const std::string &target)
{
    if (formName == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        return new PresidentialPardonForm(target);
    else
        return nullptr;
}
