#include "BitcoinExchange.hpp"

int	main()
{
 //	BitcoinExchange<int> exchange;
/*	std::ifstream	Csv;
	std::ifstream	Input = ;*/

	std::string	date = "2024-12-31";

	if (BitcoinExchange<float>::valid_date(date))
		std::cout << date << " is a valid date" << std::endl;


	return 0;
}
