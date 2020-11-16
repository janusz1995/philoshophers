

.PHONY:  all clean fclean re

NAME = philo_one

SRC = errors.c ft_atoi.c ft_itoa.c ft_put_fd.c get_time.c main.c \
		eat_sleep_think.c free.c ft_strlen.c init.c life_circle.c \
		write_action.c

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

%.o: %.c
	gcc $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(SRCO)
	gcc $(NAME) $(SRCO)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all