#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog &d);

	Dog& operator=(const Dog &d);
	using Animal::getType;
	void makeSound() const;
};
