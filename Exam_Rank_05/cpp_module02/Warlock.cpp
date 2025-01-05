#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
    : name(name), title(title)
{
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
    return this->name;
}

const std::string& Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string& newTitle)
{
    this->title = newTitle;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        this->book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string& spellName)
{
    this->book.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target)
{
    ASpell* tmp = this->book.createSpell(spellName);
    if (tmp)
        tmp->launch(target);
}
