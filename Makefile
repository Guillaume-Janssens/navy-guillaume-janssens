##
## EPITECH PROJECT, 2020
## evalexper
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c		\
		my_putstr.c	\
		my_putnbr.c	\
		my_getnbr.c	\
		signals.c	\
		my_revstr.c	\
		my_tab.c	\
		place_boat.c	\
		boats.c		\
		game.c		\
		send_attack.c	\
		board.c		\
		my_input.c	\
		str_int.c	\
		round.c		\
		other.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -I./include -W -Wall -Wextra

LDFLAGS = 	-L./printf/ -lmy

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C printf/
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C printf/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C printf/

re: 	fclean all
	make re -C printf/

