NAME = Mutant
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp MutantStack.hpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re