#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <string>
# include <map>

/*
template<typename T, typename U>
struct	is_same
{
	static const bool value = false;
};

template<typename T, typename T>
struct	is_same
{
	static const bool value = true;
};
*/

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

class	InvalidDate : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Error: bad input => ";
		}
};

template<typename T>
void	debug(std::string data, T &str)
{
	std::cout << data << str << std::endl;
}

template<typename T>
class	BitcoinExchange
{
	private:
		std::map<std::time_t, T>	_csvData;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		static std::time_t		validDate(std::string &date);
		static T			validValue(T &value);
		void				setCsvData();
		void				printCsv();
		void				compareInput(const char *path);
};

#include "BitcoinExchange.tpp"

#endif
