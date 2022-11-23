#include <iostream>
#include <string>


std::string	to_upper(std::string &str)
{
	std::string	ret(str);

	for (std::string::iterator iter=ret.begin(); iter!=ret.end(); ++iter)
		*iter = static_cast<char>(toupper(*iter));
	return (ret);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i=1; i<argc; ++i)
	{
		std::string str(argv[i]);
		str = to_upper(str);
		for (std::string::iterator iter=str.begin(); iter!=str.end(); ++iter)
			std::cout << *iter;
	}
	std::cout << std::endl;
	return (0);
}
