#include <iostream>

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap	a("frist"), b("second");

	a.attack("second");
	b.takeDamage() //# TODO
	a.attack("second");
	return (0);
}
