NAME=		PmergeMe
CMD=		c++ -std=c++98 -Wall -Wextra -Werror -fsanitize=address -MMD -MP
SRC=		PmergeMe.cpp main.cpp
OBJ=		$(SRC:.cpp=.o)
DEP=		$(SRC:.cpp=.d)

$(NAME):	 $(OBJ)
	$(CMD) $(OBJ) -o $(NAME)

%.o:		%.cpp %.hpp Makefile
	$(CMD) -c $< -o $@

all:		$(NAME)

clean:
	rm -rf $(OBJ) $(DEP)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re

-include: 	$(DEP)
