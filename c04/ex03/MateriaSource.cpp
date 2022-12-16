#include <string>

#include "MateriaSource.hpp"


MateriaSource::MateriaSource(void)
{}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = ms._slot[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ms)
{
	for (int i=0; i<_size; ++i)
	{
		delete _slot[i];
		_slot[i] = ms._slot[i]->clone();
	}
}

void		MateriaSource::learnMateria(AMateria* m)
{
	int	idx = _findEmtpySlot();
	if (idx == -1)
		return ;
	_slot[idx] = m;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	int	idx = _find(type);
	if (idx == -1)
		return (NULL);
	return (_slot[idx]->clone());
}

const int&	MateriaSource::_findEmtpySlot(void) const
{
	for (int i=0; i<_size; ++i)
		if (_slot[i] == NULL)
			return (i);
	return (-1);
}

const int&	MateriaSource::_find(const std::string name) const
{
	for (int i=0; i<_size; ++i)
		if (_slot[i] == NULL && _slot[i]->getType() == name)
			return (i);
	return (-1);
}
