#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const & other);
    Ice& operator=(Ice const & other);
    virtual ~Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif // ICE_HPP
