#include <cstdlib>
#include <ctime>

#include "Base.hpp"


int	main(void)
{
	srand(time(NULL));

	Base	*p = generate();

	identify(p);
	identify(*p);

	return (0);
}
