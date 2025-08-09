#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "WOOF WOOF! (constructor called)" << std::endl;
	brain = new Brain();
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "WOOF WOOF! (destructor called)" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &d) : Animal(d)
{
	std::cout << "Copy Dog Constructor" << std::endl;
	*this = d;
}

Dog& Dog::operator=(const Dog & d)
{
	if (this != &d)
	{
		this->type = d.getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF :D" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}
