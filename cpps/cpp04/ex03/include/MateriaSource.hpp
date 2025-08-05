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
private:
	// AMateria[4]_materias;
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
};

#endif // MateriaSource_HPP
