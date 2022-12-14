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


	std::cout << std::endl;


	ClapTrap	*c = new ClapTrap("c");

	c->attack("b");
	c->takeDamage(5);
	c->beRepaired(10);

	std::cout << std::endl;

	return (0);
}
