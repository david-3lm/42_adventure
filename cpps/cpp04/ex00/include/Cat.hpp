#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &other);

	Cat &operator=(const Cat &other);
	using Animal::getType;
	void makeSound() const;
};

