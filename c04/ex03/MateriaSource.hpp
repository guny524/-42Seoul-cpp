#pragma once
#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"


class	MateriaSource: public IMateriaSource
{
private:
	const static int	_size = 4;
	AMateria			*_slot[_size];

	int	_findEmtpySlot(void) const;
	int	_find(const std::string name) const;

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& ms);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& ms);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(const std::string& type);
};

#endif
