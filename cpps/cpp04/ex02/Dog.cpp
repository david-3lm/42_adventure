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

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF :D" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}
