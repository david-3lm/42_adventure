#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "I'm FragTrap, my own constructor itself!" << std::endl;
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
}

FragTrap::FragTrap(const std::string n) : ClapTrap(n)
{
	std::cout << "I'm FragTrap, my own name constructor!" << std::endl;
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
	std::cout << "I'm FragTrap, my own copy constructor!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "I'm FragTrap, my own destructor itself!" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "I'm FragTrap" << this->getName() << " HIGH FIVE EVERYBODY!" << std::endl;
}
