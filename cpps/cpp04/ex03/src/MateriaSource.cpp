#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Default destructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other) {
        // TODO: operador asignación
    }
    return *this;
}
