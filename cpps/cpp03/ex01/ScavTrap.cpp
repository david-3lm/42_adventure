#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\033[1m\033[33m I'm ScavTrap, my own constructor itself!" << "\033[0m" << std::endl;
	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 20;
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
	std::cout << "\033[1m\033[33m I'm ScavTrap " << n << " and I am independant to ClapTrap! >:(" << "\033[0m" << std::endl;
	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 20;
}
 
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap(s)
{
	std::cout << "\033[1m\033[33m I'm ScavTrap and this is my copy constructor, I AM NOT A COPY!" << "\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1m\033[33m I'm ScavTrap destructor called, bye cruel world!!" << "\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[1m\033[33m ScavTrap " << this->name << " | Status: Guarding Gate" << "\033[0m" << std::endl;
}
