#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Empty Animal Constructor" << std::endl;
}

Animal::Animal(const std::string t)
{
	std::cout << "Animal Constructor of type: " << t << std::endl;
	type = t;
}

Animal::Animal(const Animal &a)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = a;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "*Undefined animal sounds*" << std::endl;
}
