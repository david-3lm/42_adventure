#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ClapTrap c4;
	
	seeStats(c1);
	s1.setAttackD(50);
	s1.setEnergyP(4);
	s1.setHitP(50);
	seeStats(s1);

	/* ATTACKS */

	c1.attack("Manoleitor2000");
	s1.takeDamage(c1.getAttackD());
	s1.attack(c1.getName());
	c1.takeDamage(s1.getAttackD());
	c1.beRepaired(10);
	s1.attack(c1.getName());
	std::cout << "Invent but " << c1.getName() << " defeated" << std::endl;

	s1.guardGate();
	
	return 0;
}
