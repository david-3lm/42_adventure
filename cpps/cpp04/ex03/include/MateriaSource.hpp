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
	AMateria *materias[4];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);

	virtual void learnMateria(AMateria *mat);
	virtual AMateria* createMateria(std::string const & type);
};

#endif // MateriaSource_HPP
