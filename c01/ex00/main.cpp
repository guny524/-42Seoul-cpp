#include <iostream>

#include "Zombie.hpp"


int	main(void)
{
	Zombie	*zb = newZombie("test1");

	zb->announce();
	delete zb;
	randomChump("test2");
	return (0);
}
