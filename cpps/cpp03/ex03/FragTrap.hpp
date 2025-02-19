#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string n);
	FragTrap(const FragTrap &f);
	~FragTrap();

	using ClapTrap::operator=;
	void highFivesGuys(void) const;
};

