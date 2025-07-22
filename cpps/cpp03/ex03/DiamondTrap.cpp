#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "\033[1m\033[36m DiamondTrap " << this->name << " Empty constructor called " << "\033[0m" << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) 
  : ClapTrap(name + "_clap_name"),
	name(name)
{
	std::cout << "\033[1m\033[36m DiamondTrap " << this->name << " Name constructor called " << "\033[0m" << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d), ScavTrap(d), FragTrap(d)
{
	std::cout << "\033[1m\033[36m DiamondTrap " << this->name << " Copy constructor called " << "\033[0m" << std::endl;

	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[1m\033[36m DiamondTrap " << this->name << " Destructor called " << "\033[0m" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[1m\033[36m DiamondTrap " << this->name << " with ClapTrap name => " << ClapTrap::name << "\033[0m" << std::endl;
}
