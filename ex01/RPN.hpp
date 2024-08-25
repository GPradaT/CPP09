#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stack>

class	RPN
{
	private:
		RPN(const RPN &src);
		void	operator=(const RPN &src);

		std::stack<int>	operands;
		int		result;

	public:
		RPN();
		~RPN();

		bool		isOperator(char c) const;
		void		validInput(const std::string &input);
		void		checkEnd();

		void		solve(const std::string &input);
		int		calculator(int a, char c, int b);
		
		int		getResult() const;
};
