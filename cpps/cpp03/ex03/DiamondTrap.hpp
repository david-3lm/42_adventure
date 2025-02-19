#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& d);
	~DiamondTrap();

	using ClapTrap::operator=;
	using FragTrap::attack;
	void whoAmI();
};
