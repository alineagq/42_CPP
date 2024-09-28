#include "Intern.hpp"

struct FormCreationMapping
{
    std::string formName;
    AForm *(Intern::*createFormPtr)(const std::string &target);
};

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

// Refactored createForm to use function pointers.
AForm *Intern::createFormShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createFormRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createFormPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    FormCreationMapping formMappings[] = {
        {"shrubbery creation", &Intern::createFormShrubbery},
        {"robotomy request", &Intern::createFormRobotomy},
        {"presidential pardon", &Intern::createFormPardon}};

    const int formCount = sizeof(formMappings) / sizeof(formMappings[0]);

    for (int i = 0; i < formCount; ++i)
    {
        if (formName == formMappings[i].formName)
        {
            AForm *form = (this->*formMappings[i].createFormPtr)(target); // Call the corresponding member function.
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }

    std::cout << "Error: Form " << formName << " creation failed." << std::endl;
    return NULL;
}
