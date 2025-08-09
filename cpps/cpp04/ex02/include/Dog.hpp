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
	Dog(const Dog &d);

	Dog& operator=(const Dog &d);
	using AAnimal::getType;

	Brain *getBrain() const;
	void makeSound() const;
};
