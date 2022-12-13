#include <iostream>
#include <string>

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap	a("a"), b("b");

	a.attack("b");
	b.takeDamage(5);
	b.attack("a");
	a.takeDamage(5);
	b.beRepaired(10);
	a.attack("b");
	return (0);
}
