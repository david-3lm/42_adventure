#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	~Cat();

	using Animal::operator=;
	using Animal::getType;
	void makeSound() const;
};

