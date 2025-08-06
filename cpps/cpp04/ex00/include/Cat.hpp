#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();

	using Animal::operator=;
	using Animal::getType;
	void makeSound() const;
};

