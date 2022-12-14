#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void)
{
	FragTrap	a("a"), b("b");

	for (int i=0; i<105; ++i)
		a.attack("b");

	b.highFivesGuys();

	b.takeDamage(50);
	b.takeDamage(20);
	b.beRepaired(100);

	b.takeDamage(100);
	b.attack("a");


	std::cout << std::endl;


	ScavTrap	*c = new ScavTrap("c");

	c->attack("b");
	c->takeDamage(5);
	c->beRepaired(10);

	c->guardGate();

	delete c;


	std::cout << std::endl;


	ClapTrap	*d = new ScavTrap("d");

	d->attack("c");
	d->takeDamage(5);
	d->beRepaired(10);

	// d->guardGate();

	delete d;


	std::cout << std::endl;


	FragTrap	*e = new FragTrap("e");

	e->attack("d");
	e->takeDamage(5);
	e->beRepaired(10);

	e->highFivesGuys();

	delete e;


	std::cout << std::endl;


	ClapTrap	*f = new FragTrap("f");

	f->attack("e");
	f->takeDamage(5);
	f->beRepaired(10);

	// f->highFivesGuys();

	delete f;

	std::cout << std::endl;

	return (0);
}
