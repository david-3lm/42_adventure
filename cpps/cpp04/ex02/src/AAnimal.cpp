#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Empty AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const std::string t)
{
	std::cout << "AAnimal Constructor of type: " << t << std::endl;
	type = t;
}

AAnimal::AAnimal(const AAnimal &a)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = a;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	this->type = other.type;
	return *this;
}

std::string AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const
{
	std::cout << "*Undefined Aanimal sounds*" << std::endl;
}
