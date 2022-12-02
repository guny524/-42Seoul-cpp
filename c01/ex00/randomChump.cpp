#include <string>

#include "Zombie.hpp"


void	randomChump(std::string name)
{
	Zombie	*nzb;

	nzb = newZombie(name);
	nzb->announce();
	delete nzb;
}
