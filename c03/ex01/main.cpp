#include <iostream>
#include <string>

#include "ScavTrap.hpp"


int	main(void)
{
	ScavTrap	a("a"), b("b");

	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");

	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");

	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");
	a.attack("b");

	b.takeDamage(5);
	b.takeDamage(2);
	b.beRepaired(100);

	b.takeDamage(100);
	b.attack("a");

	return (0);
}
