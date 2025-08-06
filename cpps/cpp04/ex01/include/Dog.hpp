#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	~Dog();

	using Animal::operator=;
	using Animal::getType;

	Brain *getBrain() const;
	void makeSound() const;
};
