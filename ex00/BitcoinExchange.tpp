#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _csvData(), _inputFile(){}

template<typename T>
bool		BitcoinExchange<T>::valid_value(T &value)
{
	return value >= 0 && value <= 1000;
}

template<typename T>
bool		BitcoinExchange<T>::valid_date(std::string &date)
{
	int	dates[3];

	if (date.length() != 10)
	{
		throw InvalidDate();
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		throw InvalidDate();
		return false;
	}
	try
	{
		dates[0] = std::atoi(date.substr(0, 4).c_str());
		dates[1] = std::atoi(date.substr(5, 7).c_str());
		dates[2] = std::atoi(date.substr(8, 10).c_str());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

template<typename T>
void		fill_map()
{

}
