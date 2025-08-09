#include "Ice.hpp"

Ice::Ice() 
{
    std::cout << "Default constructor called." << std::endl;
	this->type = "ice";
}

Ice::~Ice() 
{
    std::cout << "Default destructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice &other) 
{
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria *Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}