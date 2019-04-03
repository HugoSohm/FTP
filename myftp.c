/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** myftp.c
*/

#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myftp(int port)
{
    struct sockaddr_in serverSock;
    struct sockaddr_in clientSock;
    int clientSockSize = sizeof(clientSock);
    int clientfd;
    int fd;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
    {
        printf("Error opening socket\n");
        return (-1);
    }

    serverSock.sin_port = htons(port);
    serverSock.sin_addr.s_addr = htonl(INADDR_ANY);
    serverSock.sin_family = AF_INET;

    bind(fd, (struct sockaddr *)&serverSock, sizeof(serverSock));
    listen(fd, 10);
    clientfd = accept(fd, (struct sockaddr *)&clientSock, &clientSockSize);

    write(clientfd, "Hello World!!!\n", 15);

    close(clientfd);

    return (0);
}

void help()
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    printf("\tpath\tis the path to the home directory for the Anonymous user\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        help();
    else if (argc == 2)
        myftp(atoi(argv[1]));
    else {
        printf("Invalid arguments, there is %d arguments\n", argc);
        return (84);
    }
    return (0);
}