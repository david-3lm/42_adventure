#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		materias[i] = 0;
	}
    std::cout << "Default constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{    
	for (int i = 0; i < 4; ++i) 
	{
        if (materias[i] != 0)
            delete materias[i];
    }
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

void MateriaSource::learnMateria(AMateria *mat)
{

	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i] == 0)
		{
			materias[i] = mat;
			std::cout << "Toca aprender la materia: " << mat->getType() << std::endl;
			return;
		}

	}
	
	int i = 0;
	while (i <= 3 && materias[i] != 0)
	{
		i++;
	}
	if (i <= 3)
	{
		materias[i] = mat;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;
}
