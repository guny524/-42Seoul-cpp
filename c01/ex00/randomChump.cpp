#include <string>
#include <iostream>

#include "Zombie.hpp"


void	randomChump(std::string name)
{
	Zombie	*nzb;

	nzb = newZombie(name);
	std::cout << "Zombie's name is: " << *nzb << std::endl;
	nzb->announce();
	delete nzb;
}
