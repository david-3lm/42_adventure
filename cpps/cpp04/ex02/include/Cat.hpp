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
	Cat(const Cat &other);

	Cat &operator=(const Cat &other);
	using AAnimal::getType;
	
	Brain *getBrain() const;
	void makeSound() const;
};

