#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include "SpellBook.hpp"

class Warlock {
private:
    std::string name;
    std::string title;
    SpellBook   book; // Warlock's personal spell book

    Warlock();
    Warlock(const Warlock&);
    Warlock& operator=(const Warlock&);

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);

    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    void launchSpell(const std::string& spellName, const ATarget& target);
};

#endif
