#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <string>
# include <map>

# define BTC_FIRST_DATE "2009-01-03"
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
template<typename T>
class	BitcoinExchange
{
	private:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
//		typedef char	valid[is_same<T, int>::value || is_same<T, float>::value ? 1 : -1];
		std::map<std::string, T>	_csvData;
		std::map<std::string, T>	_inputFile;
	
	public:

		static bool			valid_date(std::string &date);
		static bool			valid_value(T &value);

		class	InvalidDate : public std::exception {
			public:
				const char *what() const throw() {
					return "Error: bad input => ";
				}
		};
};

#include "BitcoinExchange.tpp"

#endif
