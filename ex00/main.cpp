#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::ifstream input(argv[1]);
		if (!input.is_open())
			return -1;
		std::map<std::time_t, T> inputDB;
		std::time_t	timestamp;
		T		value;
		while (input >> timestamp >> value)
		{

		}
	}
	return 0;
}
