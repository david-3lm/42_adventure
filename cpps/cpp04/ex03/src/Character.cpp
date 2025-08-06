#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = 0;
	}
	
    std::cout << "Default constructor called." << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i) 
	{
        if (inventory[i])
            delete inventory[i];
    }
    std::cout << "Default destructor called." << std::endl;
}

Character::Character(std::string n) : name(n)
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = 0;
	}
    std::cout << "Default constructor with name " << name << " called." << std::endl;
}

Character::Character(const Character &other) {
	std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        this->name = other.getName();
    }
    return *this;
}

std::string const &	Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
	int i = 0;
	while (inventory[i])
		i++;
	if (i <= 3)
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (inventory[idx])
		inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (inventory[idx])
		inventory[idx]->use(target);
}
