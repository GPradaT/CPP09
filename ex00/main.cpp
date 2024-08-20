#include "BitcoinExchange.hpp"

int	main()
{
	{
		std::cout << "\033[091mMAIN-----------1" << std::endl;
		std::string	date = "2024-12-31";
		std::string	date1 = "2004-02-28";
		std::string	date2 = "2024-01-31";
		std::string	date3 = "2009-12-30";
		try {
			std::cout << "=====DATE======" << std::endl;
			std::cout << date << std::endl;
			BitcoinExchange<int>::valid_date(date);
			std::cout << "=====DATE1=====" << std::endl;
			std::cout << date1 << std::endl;
			BitcoinExchange<float>::valid_date(date1);
			std::cout << "=====DATE2=====" << std::endl;
			std::cout << date2 << std::endl;
			BitcoinExchange<float>::valid_date(date2);
			std::cout << "=====DATE3=====" << std::endl;
			std::cout << date3 << std::endl;
			BitcoinExchange<int>::valid_date(date3);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[092mMAIN-----------2" << std::endl;
		std::string	date = "2024-02-31";
		std::string	date1 = "2000-02-28";
		std::string	date2 = "2021-02-31";
		std::string	date3 = "2009-12-30";
		try {
			std::cout << "=====DATE======" << std::endl;
			std::cout << date << std::endl;
			BitcoinExchange<int>::valid_date(date);
			std::cout << "=====DATE1=====" << std::endl;
			std::cout << date1 << std::endl;
			BitcoinExchange<float>::valid_date(date1);
			std::cout << "=====DATE2=====" << std::endl;
			std::cout << date2 << std::endl;
			BitcoinExchange<float>::valid_date(date2);
			std::cout << "=====DATE3=====" << std::endl;
			std::cout << date3 << std::endl;
			BitcoinExchange<int>::valid_date(date3);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
