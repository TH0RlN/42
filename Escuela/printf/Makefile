# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 10:53:49 by rarias-p          #+#    #+#              #
#    Updated: 2020/02/15 18:20:29 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=flag_pos.c print_perc.c print_num_neg.c ft_isspace.c print_perc.c ft_pprecision_int.c ft_strchr.c ft_strlen.c get_type.c itoa_hex.c print_p.c print_x.c flagger.c ft_itoa.c ft_pprecision_string.c ft_pwidth.c ft_strdup.c ft_substr.c get_width.c print_c.c print_s.c checker.c ft_atoi.c ft_pminus.c ft_printf.c ft_pzero.c ft_strjoin.c get_precision.c itoa_base.c print_num.c print_type.c

OBJ=$(SRC:.c=.o);


$(NAME):	ft_printf.h
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean