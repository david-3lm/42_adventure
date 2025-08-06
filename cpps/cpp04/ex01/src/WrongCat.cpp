#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "meow :3 (constructor called)" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "meow meow :3 (destructor called)" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "marramiau :3" << std::endl;
}