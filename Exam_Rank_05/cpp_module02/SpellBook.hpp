#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include <string>
#include "ASpell.hpp"

class SpellBook {
private:
    std::map<std::string, ASpell*> spells;

    SpellBook(const SpellBook&);            // non-copyable
    SpellBook& operator=(const SpellBook&); // non-assignable

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    ASpell* createSpell(const std::string& spellName);
};

#endif
