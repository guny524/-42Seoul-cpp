#include "BitcoinExchange.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc(argv[1]);
		btc.process();
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
