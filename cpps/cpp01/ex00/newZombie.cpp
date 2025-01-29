#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie* z = new Zombie(name);

	return (z); 
}