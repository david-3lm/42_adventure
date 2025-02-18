#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string n);
	ScavTrap(const ScavTrap& s);
	~ScavTrap();

	using ClapTrap::operator=;
	void guardGate();
};
