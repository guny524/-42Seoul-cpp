#include <iostream>
#include <string>

#include "DiamondTrap.hpp"


int	main(void)
{
	DiamondTrap	a("a"), b("b");

	a.whoAmI();

	for (int i=0; i<55; ++i)
		a.attack("b");

	b.guardGate();
	b.highFivesGuys();

	b.takeDamage(50);
	b.takeDamage(20);
	b.beRepaired(100);

	b.takeDamage(100);
	b.attack("a");


	std::cout << std::endl;


	ClapTrap	*aa = new DiamondTrap("aa");

	aa->attack("b");
	aa->takeDamage(5);
	aa->beRepaired(10);

	// c->guardGate();
	// c->highFivesGuys();

	delete aa;


	std::cout << std::endl;


	ClapTrap	*c = new DiamondTrap("c");

	c->attack("b");
	c->takeDamage(5);
	c->beRepaired(10);

	// c->guardGate();
	// c->highFivesGuys();

	delete c;


	std::cout << std::endl;


	ScavTrap	*d = new DiamondTrap("d");

	d->attack("c");
	d->takeDamage(5);
	d->beRepaired(10);

	d->guardGate();
	// d->highFivesGuys();

	delete d;


	std::cout << std::endl;


	FragTrap	*e = new DiamondTrap("e");

	e->attack("d");
	e->takeDamage(5);
	e->beRepaired(10);

	// e->guardGate();
	e->highFivesGuys();

	delete e;

	std::cout << std::endl;

	return (0);
}
