#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        sources[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    *this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (sources[i])
                delete sources[i];
            if (other.sources[i])
                sources[i] = other.sources[i]->clone();
            else
                sources[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (sources[i])
            delete sources[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!sources[i]) {
            sources[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (sources[i] && sources[i]->getType() == type)
            return sources[i]->clone();
    }
    return nullptr;
}
