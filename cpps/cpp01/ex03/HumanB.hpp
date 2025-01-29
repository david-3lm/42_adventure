#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string n);
	~HumanB();

	void attack() const;
	void setWeapon(Weapon &w);
};
