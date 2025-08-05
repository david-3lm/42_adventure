#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"


void seeStats(ClapTrap &c, std::string color)
{
	std::cout << color << std::endl;
	std::cout << "------- " << c.getName() << " -------" << std::endl;
	std::cout << "Hit Points:  " << c.getHitP() << std::endl;
	std::cout << "Energy Points:  " << c.getEnergyP() << std::endl;
	std::cout << "Attack Damage:  " << c.getAttackD() << std::endl;
	std::cout << "Ready to attack!" << std::endl;
	std::cout << "____________________" << std::endl;
	std::cout << WHITE << std::endl;
}

int main(void)
{
	ClapTrap c1("Manolo");
	ScavTrap s1("Manoleitor2000");
	FragTrap f1("Doctor Doofensmirtz");
	
	seeStats(c1, RED);
	seeStats(s1, GREEN);
	seeStats(f1, YELLOW);

	/* ATTACKS */

	c1.attack("Manoleitor2000");
	s1.takeDamage(c1.getAttackD());
	f1.attack("un pato aleatorio");
	s1.attack(c1.getName());
	c1.takeDamage(s1.getAttackD());
	c1.beRepaired(10);
	f1.beRepaired(10);
	s1.attack(c1.getName());
	std::cout << "Invent but " << c1.getName() << " defeated" << std::endl;

	s1.guardGate();
	f1.highFivesGuys();
	
	return 0;
}
