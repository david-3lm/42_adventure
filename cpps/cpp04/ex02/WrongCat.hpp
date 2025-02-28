#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();

	using WrongAnimal::operator=;
	using WrongAnimal::getType;
	void makeSound() const;
};

