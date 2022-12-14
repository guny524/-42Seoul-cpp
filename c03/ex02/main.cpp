#include <iostream>
#include <string>

#include "ScavTrap.hpp"


int	main(void)
{
	ScavTrap	a("a"), b("b");

	for (int i=0; i<55; ++i)
		a.attack("b");

	b.guardGate();

	b.takeDamage(50);
	b.takeDamage(20);
	b.beRepaired(100);

	b.takeDamage(100);
	b.attack("a");

	return (0);
}
