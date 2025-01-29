#include "Zombie.hpp"

int main( void )
{
	std::cout << "-------------MAIN DE MIEDO 2---------------" << std::endl;
	std::cout << ">> INICIAMOS HORDAAA" << std::endl;
	Zombie *h = zombieHorde(7, "PacoooozzzzzzZZZzzzZZZz");
	std::cout << ">> ELIMINAMOS HORDAAA" << std::endl;
	delete[] h;
	return 0;
}
