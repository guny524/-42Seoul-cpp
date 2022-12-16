#pragma once
#ifndef __CURE_H__
# define __CURE_H__

# include <string>

# include "ICharacter.ipp"
# include "AMateria.hpp"


class	Cure: public AMateria
{
public:
	Cure(void);
	Cure(const Cure& c);
	~Cure();

	Cure&	operator=(const Cure& c);

	Cure*	clone() const;
	void	use(ICharacter& target);
};

#endif
