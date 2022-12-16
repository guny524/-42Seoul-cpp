#include <cstddef>
#include <string>

#include "Character.hpp"


Character::Character(void)
{}

Character::Character(const std::string& name):
_name(name)
{}

Character::Character(const Character& c):
_name(c.getName())
{
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = c._slot[i]->clone();
	}
}

Character::~Character()
{
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = NULL;
	}
}

Character&	Character::operator=(const Character& c)
{
	_name = c.getName();
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = c._slot[i]->clone();
	}
}

const std::string&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *am)
{
	int	idx = _findEmtpySlot();
	if (idx == -1)
		return ;
	_slot[idx] = am;
}

void	Character::unequip(int idx)
{
	if (_slot[idx])
	{
		delete _slot[idx];
		_slot[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (!_slot[idx])
		return ;
	_slot[idx]->use(target);
}

const int&	Character::_findEmtpySlot(void) const
{
	for (int i=0; i<_size; ++i)
		if (_slot[i] == NULL)
			return (i);
	return (-1);
}
