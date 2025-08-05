#include "Character.hpp"

Character::Character() {
    std::cout << "Default constructor called." << std::endl;
}

Character::~Character() {
    std::cout << "Default destructor called." << std::endl;
}

Character::Character(std::string n) : name(n)
{
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
