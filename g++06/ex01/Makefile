NAME = serialize
SRC = Serializer.cpp main.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all