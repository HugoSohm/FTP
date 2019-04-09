##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Made by Hugo SOHM
##

SERVER_NAME		=	serveur

SERVER_SRCS    	=	./ftp_server/src/server.c	\
					./ftp_server/src/errors.c	\
					./ftp_server/src/main.c

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)
SERVER_INCL		=	-I./ftp_server/includes

####################################################

CLIENT_NAME		=	client

CLIENT_SRCS		=	./ftp_client/src/client.c	\
					./ftp_client/src/errors.c	\
					./ftp_client/src/main.c

CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)
CLIENT_INCL		=	-I./ftp_client/includes

####################################################

CC			=	gcc
RM			=	rm -f
CFLAGS		=

#####################################################

.c.o	:
	@$(CC) $(CFLAGS) $(SERVER_INCL) $(CLIENT_INCL) -c $< -o $@
	@printf " \033[34m[Compilation]\033[39m %s\n" $<

all	:	$(SERVER_OBJS) $(CLIENT_OBJS)
		@$(CC) $(SERVER_OBJS) -o $(SERVER_NAME)
		@printf "\n \033[33m[Message]\033[39m Server compilation done\n"
		@$(CC) $(CLIENT_OBJS) -o $(CLIENT_NAME)
		@printf "\n \033[33m[Message]\033[39m Client compilation done\n"

clean	:
	@$(RM) *~ $(SERVER_OBJS)
	@printf " \033[31m[Delete] \033[39m%s\n" $(SERVER_OBJS)
	@$(RM) *~ $(CLIENT_OBJS)
	@printf " \033[31m[Delete] \033[39m%s\n" $(CLIENT_OBJS)

fclean	:	clean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@printf "\n \033[31m[Delete] \033[39m%s\n\n" $(NAME)

re	:	fclean all