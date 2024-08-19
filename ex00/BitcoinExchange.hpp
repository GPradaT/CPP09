#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
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
template<typename T>
class	BitcoinExchange
{
	private:
//		typedef char	valid[is_same<T, int>::value || is_same<T, float>::value ? 1 : -1];
		std::map<std::string, T>	_csvData;
		std::map<std::string, T>	_inputFile;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);

		static bool			valid_date(std::string &date);
		static bool			valid_value(T &value);
		static void			fill_map();

		class	InvalidDate : public std::exception {
			public:
				const char *what() const throw() {
					return "Error: bad input => ";
				}
		};
};

#include "BitcoinExchange.tpp"

#endif
