#include <iostream>
#include <string>
#include <sstream>

#include "Zombie.hpp"


Zombie	*zombieHorde(int N, std::string name)
{
	std::stringstream	st;
	Zombie *horde = new Zombie[N];

	for (int i=0; i<N; ++i)
	{
		st << i;
		horde[i].setName(name + st.str());
		st.str(""); // remove all content
	}
	return (horde);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "argc is not 2" << std::endl;
		return (0);
	}
	std::stringstream	st(argv[1]);
	int	N;
	if (!(st >> N))
	{
		std::cerr << "invalide input range integer" << std::endl;
		return (0);
	}

	Zombie	*zbs = zombieHorde(N, "test");
	for (int i=0; i<N; ++i)
		zbs[i].announce();
	delete []zbs;

	return (0);
}
