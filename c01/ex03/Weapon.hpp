#pragma once
#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <iostream>


class	Weapon
{
private:
	std::string	_type;

public:
	Weapon(void);
	Weapon(const std::string& type);
	Weapon(const Weapon& wp);
	~Weapon();

	Weapon& operator=(const Weapon& wp);

	const std::string&	getType() const;
	void				setType(const std::string& type);
};

#endif
