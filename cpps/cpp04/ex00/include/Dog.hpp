#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();

	using Animal::operator=;
	using Animal::getType;
	void makeSound() const;
};
