#include "BitcoinExchange.hpp"

bool	invalid_params(int dates[3])
{
		int daysInMonth[] = {31, (((dates[0] % 4 == 0 && dates[0] % 100 != 0) 
					|| dates[0] % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return ((dates[0] > 2008 && dates[0] < 2025)
		&& (dates[1] > 0 && dates[1] < 13)
		&& !(dates[2] < 1 || dates[2] > daysInMonth[dates[1] - 1]));
}

BitcoinExchange::BitcoinExchange() : _csvData(){}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {(void)src;}

float		BitcoinExchange::validValue(float &value)
{
	value < 0 ? throw NotPositive() : 0;
	value > 1000 ? throw TooLarge() : 0;
	return value;
}

std::time_t	BitcoinExchange::validDate(std::string &date)
{
	int		dates[3];
	std::tm		time = {};
	std::time_t	FinalDate;

//	std::cout << "AQUI ESTA ENTRANDO ---> [ " << date << " ]" << std::endl;
	if (date.length() != 10 && date.length() != 11)
		throw InvalidDate();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDate();
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
	return FinalDate;
}

void		BitcoinExchange::setCsvData()
{
	std::ifstream	csv("data.csv");
	std::string line;
	if (!csv.is_open())
		throw FileError();
	std::getline(csv, line);
	for (;std::getline(csv,line);)
	{
		std::string	Date;
		float		Value;
		Date = line.substr(0, line.find(','));
		Value = strtod(line.substr(line.find(',') + 1, line.length()).c_str(), NULL);
		_csvData[validDate(Date)] = Value;
	}
}

void		BitcoinExchange::compareInput(const char *path)
{
	std::ifstream	input(path);

	if (!input.is_open())
		throw FileError();
	std::string	line;
	std::getline(input, line);
	for(;std::getline(input, line);)
	{
		std::cout << std::endl << std::endl;
		if (line.empty())
			continue ;
		std::stringstream	tokens(line);
		std::string		toDate;
		float			toMult = 0;
		char			pipe = 0;
		try {
			while (tokens >> toDate >> pipe >> toMult)
			{
				std::cout << "Value -> " << toDate << std::endl;
				std::cout << "Value -> " << pipe << std::endl;
				std::cout << "Value -> " << toMult << std::endl;
			}
			if ((!tokens.eof() && tokens.fail()) || pipe == 0)
				throw InvalidDate();
		} catch(std::exception &e) {
			std::cout << e.what() << line << std::endl;
			continue ;
		}
		try {
			std::time_t Date = validDate(toDate);
			std::map<time_t, float>::iterator it = _csvData.lower_bound(Date);
			if (it->first != Date && it != _csvData.begin())
				it--;
			float ValidValue = validValue(toMult);
			float value = it->second * ValidValue;
			std::cout << toDate << " => " << ValidValue << " = " << value << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
		/*try{
			while (tokens >> toDate >> pipe >> toMult)
			{
				std::cout << toMult << " << toMult " << std::endl;
				std::cout << pipe << " << pipe" << std::endl;
				std::cout << toDate << " << toDate" << std::endl;
				validDate(toDate);
			}

			if (!tokens.eof())
				throw InvalidDate();
			std::cout << "LIINE ENDED" << std::endl;

		} catch(std::exception &e) {
			std::cout << e.what() << line << std::endl;
			continue ;
		}*/

void		BitcoinExchange::printCsv()
{
	for (std::map<std::time_t, float>::const_iterator it = _csvData.begin(); it != _csvData.end(); ++it)
		std::cout << "time-> " << it->first << " value -> " << it->second << std::endl;

}
