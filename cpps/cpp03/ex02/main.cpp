#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void seeStats(ClapTrap &c)
{
	std::cout << "------- " << c.getName() << " -------" << std::endl;
	std::cout << "Hit Points:  " << c.getHitP() << std::endl;
	std::cout << "Energy Points:  " << c.getEnergyP() << std::endl;
	std::cout << "Attack Damage:  " << c.getAttackD() << std::endl;
	std::cout << "Ready to attack!" << std::endl;
	std::cout << "____________________" << std::endl;


}

int main(void)
{
	ClapTrap c1("Manolo");
	ScavTrap s1("Manoleitor2000");
	FragTrap f1("Doctor Doofensmirtz");
	
	seeStats(c1);
	seeStats(s1);
	seeStats(f1);

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
