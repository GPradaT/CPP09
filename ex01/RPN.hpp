#pragma once

#include <iostream>
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
		void		validInput(const std::string &input);
//		void		solve();
};
