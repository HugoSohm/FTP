/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** client.c
*/

#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int client(char *address, int port)
{
	struct sockaddr_in clientSock;
    char buffer[128];
	int clientfd;
	int fd;

	fd = socket(AF_INET, SOCK_STREAM, 0);

	clientSock.sin_port = htons(port);
    clientSock.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientSock.sin_family = AF_INET;

	connect(fd, (struct sockaddr*)&clientSock, sizeof(clientSock));

    memset(buffer, '\0', 128);
    read(fd, buffer, 128);

    printf("received %s\n", buffer);

    clientfd = shutdown(fd, SHUT_RDWR);
	clientfd = close(fd);

	return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3)
        client(argv[1], atoi(argv[2]));
    else {
        printf("Invalid arguments, there is %d arguments\n", argc);
        return (84);
    }
    return (0);
}