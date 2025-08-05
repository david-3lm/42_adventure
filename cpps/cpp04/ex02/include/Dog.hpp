#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *brain;
public:
	Dog();
	~Dog();

	using AAnimal::operator=;
	using AAnimal::getType;

	Brain *getBrain() const;
	void makeSound() const;
};
