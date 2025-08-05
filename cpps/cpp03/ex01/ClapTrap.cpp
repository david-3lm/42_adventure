#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitP(10), _energyP(10), _attackD(0)
{
	std::cout << "ClapTrap constructor called!" << std::endl;
	this->name = "ClapTrap";
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = c;
}

ClapTrap::ClapTrap(const std::string n) : _hitP(10), _energyP(10), _attackD(0)
{
	std::cout << "ClapTrap Constructor with name " << n << " called!" << std::endl;
	this->name = n;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << "Operator = overload called!" << std::endl;
	this->setName(c.getName());
	this->setAttackD(c.getAttackD());
	this->setEnergyP(c.getEnergyP());
	this->setHitP(c.getHitP());
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int ClapTrap::getHitP(void) const
{
	return this->_hitP;
}

unsigned int ClapTrap::getEnergyP(void) const
{
	return this->_energyP;
}

unsigned int ClapTrap::getAttackD(void) const
{
	return this->_attackD;
}

void ClapTrap::setName(const std::string n)
{
	this->name = n;
}

void ClapTrap::setHitP(const unsigned int amount)
{
	this->_hitP = amount;
}

void ClapTrap::setEnergyP(const unsigned int amount)
{
	this->_energyP = amount;
}

void ClapTrap::setAttackD(const unsigned int amount)
{
	this->_attackD = amount;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyP <= 0)
		return ;
	std::cout << "ClapTrap " << this->name << " attacks " << target 
		<< ", causing " << this->_attackD << " points of damage!" << std::endl;
	this->_energyP--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << 
		amount << " points of damage!" << std::endl;
	if (amount > this->_hitP)
		_hitP = 0;
	else
		this->_hitP -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyP <= 0)
		return ;
	std::cout << "ClapTrap " << this->name << " repaired " << 
	amount << " points of damage!" << std::endl;
	this->_hitP += amount;
	this->_energyP--;
}
