#include "BitcoinExchange.hpp"
/*
template class BitcoinExchange<int>;
template class BitcoinExchange<float>;
*/

bool	invalid_params(int dates[3])
{
		int daysInMonth[] = {31, (((dates[0] % 4 == 0 && dates[0] % 100 != 0) 
					|| dates[0] % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return ((dates[0] > 2008 && dates[0] < 2025)
		&& (dates[1] > 0 && dates[1] < 13)
		&& !(dates[2] < 1 || dates[2] > daysInMonth[dates[1] - 1]));
}

template<typename T>
BitcoinExchange<T>::BitcoinExchange() : _csvData(){}

template<typename T>
BitcoinExchange<T>::~BitcoinExchange() {}

template<typename T>
BitcoinExchange<T>::BitcoinExchange(const BitcoinExchange &src) {(void)src;}

template<typename T>
bool		BitcoinExchange<T>::validValue(T &value)
{
	return value >= 0 && value <= 1000;
}

template<typename T>
std::time_t	BitcoinExchange<T>::validDate(std::string &date)
{
	int		dates[3];
	std::tm		time = {};
	std::time_t	FinalDate;

	if (date.length() != 10)
		throw InvalidDate();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDate();
	try
	{
		dates[0] = std::atoi(date.substr(0, 4).c_str());
		dates[1] = std::atoi(date.substr(5, 7).c_str());
		dates[2] = std::atoi(date.substr(8, 10).c_str());
		if (!invalid_params(dates))
			throw InvalidDate();
		time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
		time.tm_mon = std::atoi(date.substr(5, 7).c_str()) - 1;
		time.tm_mday = std::atoi(date.substr(8, 10).c_str()) - 1;
		FinalDate = std::mktime(&time);
		if (FinalDate > std::time(0) || FinalDate == -1)
			throw InvalidDate();	
	} catch (std::exception &e) {
		std::cout << e.what() << date << std::endl;
	}
	return FinalDate;
}

template<typename T>
void		BitcoinExchange<T>::setCsvData()
{
	std::ifstream	csv("data.csv");
	std::string line;
	if (!csv.is_open())
		throw FileError();
	std::getline(csv, line);
	for (;std::getline(csv,line);)
	{
		std::string	Date;
		T		Value;
		Date = line.substr(0, line.find(','));
//		std::cout << line.substr(line.find(',') + 1, line.length()).c_str() << std::endl;
		Value = std::strtod(line.substr(line.find(',') + 1, line.length()).c_str(), NULL);
	/*	std::cout << "SUUUU --> " << Date << std::endl;
		std::cout << std::setprecision(2) << "SUUUU --> " << Value << std::endl;
		std::cout << std::fixed;*/
		_csvData.insert(std::make_pair<std::time_t, T>(validDate(Date), validValue(Value)));
//		_csvData[validDate(Date)] = validValue(Value);
	}
}

template<typename T>
void		BitcoinExchange<T>::printCsv()
{
	for (typename std::map<std::time_t, T>::const_iterator it = _csvData.begin(); it != _csvData.end(); ++it)
		std::cout << "time-> " << it->first << " value -> " << it->second << std::endl;

}

/*
template<typename T>
void		fill_map()
{

}
*/
