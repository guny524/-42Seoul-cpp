#include <iostream>
#include <string>

#include "whatever.hpp"


int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	// //////////


	// int	ai = 1;
	// const int	bi = 2;

	// std::cout << ai << std::endl;
	// std::cout << bi << std::endl;
	// std::cout << std::endl;

	// std::cout << min(ai, bi) << std::endl;
	// std::cout << max(ai, bi) << std::endl;
	// std::cout << std::endl;

	// swap(ai, bi);

	// std::cout << ai << std::endl;
	// std::cout << bi << std::endl;
	// std::cout << std::endl;

	// std::cout << min(ai, bi) << std::endl;
	// std::cout << max(ai, bi) << std::endl;
	// std::cout << std::endl;

	// //////////

	// float	af = 1;
	// float	bf = 2;

	// std::cout << af << std::endl;
	// std::cout << bf << std::endl;
	// std::cout << std::endl;

	// std::cout << min(af, bf) << std::endl;
	// std::cout << max(af, bf) << std::endl;
	// std::cout << std::endl;

	// swap(af, bf);

	// std::cout << af << std::endl;
	// std::cout << bf << std::endl;
	// std::cout << std::endl;

	// std::cout << min(af, bf) << std::endl;
	// std::cout << max(af, bf) << std::endl;
	// std::cout << std::endl;

	// TODO remove
	// Awesome a(2), b(4);

	// swap(a, b);
	// std::cout << a << " " << b << std::endl;
	// std::cout << max(a, b) << std::endl;
	// std::cout << min(a, b) << std::endl;

	return 0;
}
