#include "BitcoinExchange.hpp"

int	main()
{
//	BitcoinExchange<int> exchange;
/*	std::ifstream	Csv;
	std::ifstream	Input = ;*/

	std::string	date = "2024-12-31";
	std::string	date1 = "2004-13-31";
	std::string	date2 = "2024-14-31";
	std::string	date3 = "2009-11-30";
	try {
		std::cout << "=====DATE======" << std::endl;
		BitcoinExchange<int>::valid_date(date);
		std::cout << "=====DATE1=====" << std::endl;
		BitcoinExchange<float>::valid_date(date1);
		std::cout << "=====DATE2=====" << std::endl;
		BitcoinExchange<float>::valid_date(date2);
		std::cout << "=====DATE3=====" << std::endl;
		BitcoinExchange<int>::valid_date(date3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 1;
}
