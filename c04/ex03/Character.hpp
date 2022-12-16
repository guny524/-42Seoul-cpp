#pragma once
#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include <string.h>

# include "ICharacter.ipp"
# include "AMateria.hpp"


class	Character: public ICharacter
{
private:
	std::string			_name;
	const static int	_size = 4;
	AMateria*			_slot[_size];

	const int&	_findEmtpySlot(void) const;

public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& c);
	~Character();

	Character&	operator=(const Character& c);

	const std::string&	getName() const;
	void				equip(AMateria *am);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif
