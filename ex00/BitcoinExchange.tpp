#include "BitcoinExchange.hpp"
/*
template class BitcoinExchange<int>;
template class BitcoinExchange<float>;
*/

static bool	invalid_params(int dates[3])
{
	return ((dates[0] > 2008 && dates[0] < 2025)
		&& (dates[1] > 0 && dates[1] < 13));
}

template<typename T>
BitcoinExchange<T>::BitcoinExchange() : _csvData(), _inputFile(){}

template<typename T>
BitcoinExchange<T>::~BitcoinExchange() {}

template<typename T>
BitcoinExchange<T>::BitcoinExchange(const BitcoinExchange &src) {(void)src;}

template<typename T>
bool		BitcoinExchange<T>::valid_value(T &value)
{
	return value >= 0 && value <= 1000;
}

template<typename T>
bool		BitcoinExchange<T>::valid_date(std::string &date)
{
	int	dates[3];
	std::tm	time = {};

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
		std::cout << "Value date[0]-> " << dates[0] << std::endl;
		std::cout << "Value date[1]-> " << dates[1] << std::endl;
		std::cout << "Value date[2]-> " << dates[2] << std::endl;
		if (!invalid_params(dates))
			throw InvalidDate();
		time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
		time.tm_mon = std::atoi(date.substr(5, 7).c_str()) - 1;
		time.tm_mday = std::atoi(date.substr(8, 10).c_str()) - 1;
		std::time_t fecha_real = std::mktime(&time);
		if (fecha_real > std::time(0))
			throw InvalidDate();	
		std::cout << "valor final de fecha real --> " << fecha_real << std::endl;
		std::cout << "Value tm_year -> " << time.tm_year << std::endl;
		std::cout << "Value tm_mon -> " << time.tm_mon << std::endl;
		std::cout << "Value tm_mday -> " << time.tm_mday << std::endl;
		std::cout << "Value date[1]-> " << dates[1] << std::endl;
		std::cout << "Value date[2]-> " << dates[2] << std::endl;
		dates[0] = std::atoi(date.substr(0, 4).c_str());
		std::cout << dates[0] << " <-- values dates[0]" << std::endl;
		if (dates[0] < 2009 || dates[0] > 2024)
		{
			std::cout<<"haaaa"<<std::endl;
			throw InvalidDate();
		}
//		if ((dates[1] = std::atoi(date.substr(5, 7).c_str())) < 1 || dates[1] > 12)
//			throw InvalidDate();
		dates[2] = std::atoi(date.substr(8, 10).c_str());
		int daysInMonth[] = {31, (((dates[0] % 4 == 0 && dates[0] % 100 != 0) || dates[0] % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (dates[2] < 1 || dates[2] > daysInMonth[dates[1] - 1]) 
			throw InvalidDate();
		
	} catch (std::exception &e) {
		std::cout << e.what() << date << std::endl;
		return false;
	}
	return true;
}


/*
template<typename T>
void		fill_map()
{

}
*/
