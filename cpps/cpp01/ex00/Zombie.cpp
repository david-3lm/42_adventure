#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
	name = n;
	std::cout << name << ": Me creé" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " brain't (Destroyed)" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
