#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "WOOF WOOF! (constructor called)" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "WOOF WOOF! (destructor called)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF :D" << std::endl;
}