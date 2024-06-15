#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* sources[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    MateriaSource& operator=(MateriaSource const & other);
    virtual ~MateriaSource();
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP
