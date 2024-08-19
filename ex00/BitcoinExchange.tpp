#include "BitcoinExchange.hpp"

template<typename T>
bool		BitcoinExchange<T>::valid_value(T &value)
{
	return value >= 0 && value <= 1000;
}

template<typename T>
bool		BitcoinExchange<T>::valid_date(std::string &date)
{
//	int	dates[3];

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;


}
