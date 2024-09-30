NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
#-fsanitize=thread

SRC = detach.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

flcean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re