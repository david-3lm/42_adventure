#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n) { }

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;	
}

void HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}
