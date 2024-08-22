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
T		BitcoinExchange<T>::validValue(T &value)
{
	value < 0 ? throw NotPositive() : 0;
	value > 1000 ? throw TooLarge() : 0;
	return value;
	//return (value >= 0 && value <= 1000) ? value : -1;
}

template<typename T>
std::time_t	BitcoinExchange<T>::validDate(std::string &date)
{
	int		dates[3];
	std::tm		time = {};
	std::time_t	FinalDate;

	if (date.length() != 10 /*&& date.length() != 11*/)
		throw InvalidDate();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDate();
	try
	{
		dates[0] = std::atoi(date.substr(0, 4).c_str());
		dates[1] = std::atoi(date.substr(5, 7).c_str());
		dates[2] = std::atoi(date.substr(8, 10).c_str());
		if (!invalid_params(dates)){
			throw InvalidDate();}
		time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
		time.tm_mon = std::atoi(date.substr(5, 7).c_str()) - 1;
		time.tm_mday = std::atoi(date.substr(8, 10).c_str()) - 1;
		FinalDate = std::mktime(&time);
		if (FinalDate > std::time(0) || FinalDate == -1)
			{std::cout << "D" << std::endl;throw InvalidDate();}
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
		Value = strtod(line.substr(line.find(',') + 1, line.length()).c_str(), NULL);
		_csvData[validDate(Date)] = Value;
	}
}

template<typename T>
void		BitcoinExchange<T>::compareInput(const char *path)
{
	std::ifstream	input(path);

	if (!input.is_open())
		throw FileError();
	std::string	line;
	std::getline(input, line);
	for(;std::getline(input, line);)
	{
		std::string toCheck = line.substr(0, line.find("|") ? line.find("|") - 1 : line.length());
		try {
			std::time_t Date = validDate(toCheck);
			typename std::map<time_t, T>::iterator it = _csvData.lower_bound(Date);
			if (it->first != Date && it != _csvData.begin())
				it--;
			T Multiplicator = strtod(line.substr(line.find("|") + 1).c_str(), NULL);
			T ValidValue = validValue(Multiplicator);
			T value = it->second * ValidValue;
			std::cout << toCheck << " => " << ValidValue << " = " << value << std::endl;
		} catch (InvalidDate &e) {
			std::cout << e.what() + toCheck << std::endl;
			continue ;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

template<typename T>
void		BitcoinExchange<T>::printCsv()
{
	for (typename std::map<std::time_t, T>::const_iterator it = _csvData.begin(); it != _csvData.end(); ++it)
		std::cout << "time-> " << it->first << " value -> " << it->second << std::endl;

}
