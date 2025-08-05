#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "meow :3 (constructor called)" << std::endl;
	brain = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "meow meow :3 (destructor called)" << std::endl;
	delete brain;
}

void Cat::makeSound() const 
{
	std::cout << "marramiau :3" << std::endl;
}


Brain *Cat::getBrain() const
{
	return this->brain;
}