##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Made by Hugo SOHM
##

NAME		=	myftp

SRCS    	=	src/server.c		\
				src/errors.c		\
				src/functions.c		\
				src/init.c			\
				src/check.c			\
				src/commands.c		\
				src/commands2.c		\
				src/commands3.c		\
				src/main.c

OBJS		=	$(SRCS:.c=.o)
INCL		=	-I./includes

####################################################

CC			=	gcc
RM			=	rm -f
CFLAGS		=

#####################################################

.c.o	:
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@
	@printf " \033[34m[Compilation]\033[39m %s\n" $<

all	:	$(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\n \033[33m[Message]\033[39m Server compilation done\n"

clean	:
	@$(RM) *~ $(OBJS)
	@printf " \033[31m[Delete] \033[39m%s\n" $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)
	@printf "\n \033[31m[Delete] \033[39m%s\n\n" $(NAME)

re	:	fclean all