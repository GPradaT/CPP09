#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <string>
# include <map>

class	NotPositive : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Error: not a positive number.";
	}
};

class	TooLarge : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Error: too large a number.";
	}
};

class	FileError : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Error: could not open file.";
		}
};

class	BadInput : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Error: bad input => ";
		}
};

class	BitcoinExchange
{
	private:
		std::map<std::time_t, float>	_csvData;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		static std::time_t		validDate(std::string &date);
		static float			validValue(float &value);
		void				setCsvData();
		void				printCsv();
		void				compareInput(const char *path);
};

#endif
