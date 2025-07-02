#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Default constructor called." << std::endl;
}

Cure::~Cure()
{
    std::cout << "Default destructor called." << std::endl;
}

Cure::Cure(const Cure &other)
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

void use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}