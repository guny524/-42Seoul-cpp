#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(void);
	Zombie(const std::string name);
	Zombie(const Zombie& zb);
	~Zombie();

	Zombie& operator=(const Zombie& zb);

	std::string	getName(void);
	void		setName(std::string name);

	void	announce(void);

};

std::ostream& operator<<(std::ostream& out, Zombie &zb);

Zombie	*zombieHorde(int N, std::string name);

#endif
