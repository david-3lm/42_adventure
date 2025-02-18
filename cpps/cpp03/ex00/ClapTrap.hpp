#pragma once
#include <iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int _hitP;
	unsigned int _energyP;
	unsigned int _attackD;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& c);
	ClapTrap(const std::string n);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& c);

	std::string getName(void) const;
	unsigned int getHitP(void) const;
	unsigned int getEnergyP(void) const;
	unsigned int getAttackD(void) const;
	void setName(const std::string n);
	void setHitP(const unsigned int amount);
	void setEnergyP(const unsigned int amount);
	void setAttackD(const unsigned int amount);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

