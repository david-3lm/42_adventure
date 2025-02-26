#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const std::string t);
	WrongAnimal(const WrongAnimal& a);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);
	std::string getType() const;

	void makeSound() const;
};
