NAME = rush-02
cc = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJS =  main.o
all: $(NAME)
$(NAME):
    gcc $(CFLAGS) -c $(SRC)
    gcc $(CFLAGS)  $(OBJS) -o $(NAME)
clean:
    rm -rf $(OBJS)
fclean:
    rm -rf $(NAME)
