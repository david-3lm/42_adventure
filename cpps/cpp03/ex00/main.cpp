#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1 = ClapTrap("Manolo");
	ClapTrap c2 = ClapTrap("Paco");
	ClapTrap c3 = ClapTrap("Recesvinto");
	ClapTrap c4 = ClapTrap();
	
	c1.attack("Paco");
	c3.beRepaired(10);
	c2.takeDamage(33);
	c4.beRepaired(19);
	return 0;
}
