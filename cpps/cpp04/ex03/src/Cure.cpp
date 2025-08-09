#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
    std::cout << "Default constructor called." << std::endl;
}

Cure::~Cure()
{
    std::cout << "Default destructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure &other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria *Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}