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
	Dog(const Dog &d);

	Dog& operator=(const Dog &d);
	using Animal::getType;

	Brain *getBrain() const;
	void makeSound() const;
};
