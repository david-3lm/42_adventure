#include "AMateria.hpp"

AMateria::AMateria() : type("NO IDEA")
{
    std::cout << "Default Materia constructor called." << std::endl;
}

AMateria::AMateria(std::string const &t) : type(t)
{
    std::cout << "Materia constructor of type " << type << std::endl;
}

AMateria::AMateria(AMateria const &mat)
{
    std::cout << "Materia copy constructor called." << std::endl;
    *this = mat;
}

AMateria::~AMateria()
{
    std::cout << "Materia destructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &mat)
{
    if (this != &mat)
        this->type = mat.type;
    return *this;
}

void AMateria::use(ICharacter &target)
{
}
