#include "BitcoinExchange.hpp"

int	main()
{
	BitcoinExchange<int> exchange;
/*	std::ifstream	Csv;
	std::ifstream	Input = ;*/

	std::string	date = "1997-12-31";

	if (BitcoinExchange<int>::valid_date(date))
		std::cout << date << " is a valid date" << std::endl;


	return 0;
}
