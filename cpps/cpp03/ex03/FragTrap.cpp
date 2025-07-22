#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[1m\033[32m I'm FragTrap, my own constructor itself!" << "\033[0m" << std::endl;
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
}

FragTrap::FragTrap(const std::string n) : ClapTrap(n)
{
	std::cout << "\033[1m\033[32m I'm FragTrap, my own name constructor!" << "\033[0m" << std::endl;
	this->_hitP = 100;
	this->_energyP = 100;
	this->_attackD = 30;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
	std::cout << "\033[1m\033[32m I'm FragTrap, my own copy constructor!" << "\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1m\033[32m I'm FragTrap, my own destructor itself!" << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "\033[1m\033[32m I'm FragTrap" << this->getName() << " HIGH FIVE EVERYBODY!" << "\033[0m" << std::endl;
}
