#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "I'm ScavTrap, my own constructor itself!" << std::endl;
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
	std::cout << "I'm ScavTrap " << n << " and I am independant to ClapTrap! >:(" << std::endl;
}
 
ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap(s)
{
	std::cout << "I'm ScavTrap and this is my copy constructor, I AM NOT A COPY!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "I'm ScavTrap destructor called, bye cruel world!!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " | Status: Guarding Gate" << std::endl;
}
