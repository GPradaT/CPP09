#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	try {
	if (argc == 2)
	{
		BitcoinExchange	btc1;
		btc1.setCsvData();
		btc1.compareInput(argv[1]);
	}
	} catch (FileError &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
