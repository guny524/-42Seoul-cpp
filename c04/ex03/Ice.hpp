#pragma once
#ifndef __ICE_H__
# define __ICE_H__

# include <string>

# include "ICharacter.ipp"
# include "AMateria.hpp"


class	Ice: public AMateria
{
public:
	Ice(void);
	Ice(const Ice& ice);
	~Ice();

	Ice&	operator=(const Ice& ice);

	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif
