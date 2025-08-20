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

Cat::Cat(const Cat &other)
{
	std::cout << "Copy Cat Constructor" << std::endl;
	*this = other;
	brain = new Brain();
}

Cat& Cat::operator=(const Cat & other)
{
	if (this != &other)
	{
		this->type = other.getType();
	}
	return *this;
}


void Cat::makeSound() const
{
	std::cout << "marramiau :3" << std::endl;
}


Brain *Cat::getBrain() const
{
	return this->brain;
}