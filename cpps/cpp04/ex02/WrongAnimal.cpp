#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Empty WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string t)
{
	std::cout << "WrongAnimal Constructor of type: " << t << std::endl;
	type = t;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = a;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*NaA (Not an Animal) sound*" << std::endl;
}
