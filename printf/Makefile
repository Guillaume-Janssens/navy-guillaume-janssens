##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME    =       libmy.a

SRC     =       lib/my/my_printf.c  	           	\
                lib/my/my_putchar.c           		\
                lib/my/my_putstr.c            		\
		lib/my/my_strlen.c			\
		lib/my/my_put_nbr_base.c 		\
		lib/my/my_flag_finder.c			\
		lib/my/my_void_flags.c			\
		lib/my/my_void_flags2.c			\

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -Werror -W -Wall -Wextra -I./lib/my/include

LDFLAGS =       -L./ -lmy

all:    $(NAME)

$(NAME):        $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    	fclean $(NAME)
