#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string t);
	Animal(const Animal& a);
	~Animal();

	Animal& operator=(const Animal& other);
	std::string getType() const;

	virtual void makeSound() const;
};
