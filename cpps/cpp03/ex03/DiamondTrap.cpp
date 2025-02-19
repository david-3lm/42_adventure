#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap " << this->name << " Empty constructor called " << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) 
  : ClapTrap(name + "_clap_name"),
	name(name)
{
	std::cout << "DiamondTrap " << this->name << " Name constructor called " << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d), ScavTrap(d), FragTrap(d)
{
	std::cout << "DiamondTrap " << this->name << " Copy constructor called " << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " Destructor called " << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->name << " with ClapTrap name => " << ClapTrap::name << std::endl;
}
