#include <iostream>
#include <string>

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap	a("a"), b("b");

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
