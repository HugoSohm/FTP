##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Made by Hugo SOHM
##

NAME=		myftp

SRC=		myftp.c

OBJ=		$(SRC:.c=.o)

CFLAGS+=	-W -Wall -Wextra

all:
			gcc -o $(NAME) $(SRC)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
