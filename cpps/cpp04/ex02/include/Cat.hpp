#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;
public:
	Cat();
	~Cat();

	using AAnimal::operator=;
	using AAnimal::getType;
	
	Brain *getBrain() const;
	void makeSound() const;
};

