#include "BitcoinExchange.hpp"

#include <iostream>

int main( int ac, char **av ) {

	if (ac != 2) {
		std::cout << "Usage: ./build/btc <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange be;
		be.loadDataBase("data.csv");
		be.inputParser(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}