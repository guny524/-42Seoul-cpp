#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>


int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "argument count is not 3" << std::endl;
		return (1);
	}

	std::ifstream	ifile(argv[1]);

	if (ifile.fail())
	{
		std::cerr << "file dose not opened" << std::endl;
		return (1);
	}

	std::stringstream	st;

	ifile >> std::noskipws;
	st << ifile.rdbuf();
	ifile.close();

	std::string	str = st.str();

	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ofstream	ofile(std::string(argv[1]) + ".replace");

	size_t	pos = 0;
	size_t	pre = 0;
	std::string test;
	while (pre < str.size())
	{
		pos = str.find(s1, pre);
		if (std::string::npos == pos)
			break;
		ofile << str.substr(pre, pos - pre);
		ofile << s2;
		pre = pos + s1.size();
	}
	ofile << str.substr(pre, str.size() - pre);
	ofile.close();

	return (0);
}
