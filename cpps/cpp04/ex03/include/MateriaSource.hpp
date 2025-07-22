#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};



class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();                          // Constructor por defecto
    ~MateriaSource();                         // Destructor
    MateriaSource(const MateriaSource &other);  // Constructor copia
    MateriaSource &operator=(const MateriaSource &other); // Operador asignación
};

#endif // MateriaSource_HPP
