#pragma once

#include <iostream>

class AAnimal 
{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const std::string t);
	AAnimal(const AAnimal& a);
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& other);
	std::string getType() const;

	virtual void makeSound() const = 0;
};
