#include "RPN.hpp"
#include <iostream>


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: expression must be specified as argument ./RPN \"1 2 +\"" << std::endl;
		return 1;
	}

	try
	{
		RPN	rpn(argv[1]);
		rpn.run();
	}
	catch (const std::exception &e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
