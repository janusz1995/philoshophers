# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drina <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 18:14:06 by drina             #+#    #+#              #
#    Updated: 2020/11/19 18:14:08 by drina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:  all clean fclean re

NAME = philo_two

SRC =   errors.c ft_atoi.c ft_itoa.c ft_put_fd.c get_time.c main.c \
		eat_sleep_think.c free.c ft_strlen.c init.c life_circle.c \
		write_action.c

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(SRCO)
	gcc ${FLAGS} -o ${NAME} ${SRCO} -lpthread

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
