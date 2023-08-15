NAME = Brain
SRC = *.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all fclean clean re
