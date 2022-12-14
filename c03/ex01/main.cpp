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


	std::cout << std::endl;


	ClapTrap	c = ScavTrap("c");

	c.attack("b");
	c.takeDamage(5);
	c.beRepaired(10);

	// c.guardGate();

	std::cout << std::endl;


	ScavTrap	*d = new ScavTrap("d");

	d->attack("c");
	d->takeDamage(5);
	d->beRepaired(10);

	d->guardGate();

	delete d;


	std::cout << std::endl;


	ClapTrap	*e = new ScavTrap("e");

	e->attack("d");
	e->takeDamage(5);
	e->beRepaired(10);

	// e->guardGate();

	delete e;

	std::cout << std::endl;

	return (0);
}
