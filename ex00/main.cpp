#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		BitcoinExchange<int>	btc1;
	//	BitcoinExchange<float>	btc2;
		btc1.compareInput(argv[1]);
	//	btc2.compareInput(argv[1]);
	}
	return 0;
}
