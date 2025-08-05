#include "ClapTrap.hpp"

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
	ClapTrap c1 = ClapTrap("Manolo");
	ClapTrap c2 = ClapTrap("Paco");
	ClapTrap c3 = ClapTrap("Recesvinto");
	ClapTrap c4 = ClapTrap();
	
	seeStats(c1, RED);
	seeStats(c2, GREEN);
	seeStats(c3, CYAN);
	seeStats(c4, MAGENTA);
	c1.attack("Paco");
	c3.beRepaired(10);
	c2.takeDamage(3);
	c4.beRepaired(19);
	seeStats(c1, RED);
	seeStats(c2, GREEN);
	seeStats(c3, CYAN);
	seeStats(c4, MAGENTA);
	return 0;
}
