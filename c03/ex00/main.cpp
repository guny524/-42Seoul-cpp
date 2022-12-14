#include <iostream>
#include <string>

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap	a("a"), b("b");

	for (int i=0; i<15; ++i)
		a.attack("b");

	b.takeDamage(5);
	b.takeDamage(2);
	b.beRepaired(100);

	b.takeDamage(100);
	b.attack("a");

	ClapTrap	*c = new ClapTrap("c");

	c->attack("b");
	c->takeDamage(5);
	b.beRepaired(10);

	return (0);
}
