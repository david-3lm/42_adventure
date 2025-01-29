#pragma once
#include <iostream>
class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string t);
	~Weapon();

	void setType(std::string t);
	std::string getType();
};
