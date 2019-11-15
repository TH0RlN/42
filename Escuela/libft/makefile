# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 16:56:52 by rarias-p          #+#    #+#              #
#    Updated: 2019/11/13 17:32:07 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= *.c

OBJ=$(SRC:.c=.o);

$(NAME):	libft.h
		$(CC) $(CFLAGS) -C $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

re: fclean all

.PHONY: clean fclean