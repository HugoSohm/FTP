/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** server.c
*/

#include "../includes/server.h"

int server(int port, char *path)
{
    fd_set readfds;
    struct sockaddr_in serverSock;
    struct sockaddr_in clientSock;
    int clientSockSize = sizeof(clientSock);
    char infoConnect[INET_ADDRSTRLEN];
    char buffer[BUFSIZE];
    int clientfd;
    int serverfd;
    int optval = 1;
    int n;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);

    if (serverfd < 0)
        perror("ERROR opening socket");

    setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

    serverSock.sin_port = htons(port);
    serverSock.sin_addr.s_addr = htonl(INADDR_ANY);
    serverSock.sin_family = AF_INET;

    if (bind(serverfd, (struct sockaddr *)&serverSock, sizeof(serverSock)) == -1)
        perror("Error on binding");
    
    if (listen(serverfd, 10) == -1)
        perror("Error on listen");

    while (42) {
        FD_ZERO(&readfds);
        FD_SET(serverfd, &readfds);
        FD_SET(0, &readfds);

        if (select(serverfd + 1, &readfds, 0, 0, 0) == -1)
            perror("Error in select");

        if (FD_ISSET(0, &readfds))
            printf("Writing in server\n");

        if (FD_ISSET(serverfd, &readfds)) {
            clientfd = accept(serverfd, (struct sockaddr *)&clientSock, (socklen_t*)&clientSockSize);

            if (inet_ntop(AF_INET, &clientSock.sin_addr.s_addr, infoConnect,sizeof(infoConnect)) != NULL)
                printf("Connection from %s:%d\n", infoConnect, ntohs(clientSock.sin_port));
            write(clientfd, "220 Hello\n", 10);

            if (clientfd == -1)
                perror("Error on accept");
            
            while (42) {
                bzero(buffer, BUFSIZE);
                memset(buffer, 0, BUFSIZE);
                read(clientfd, buffer, BUFSIZE);
                buffer[strlen(buffer)-2] = '\0';

                if (strcmp(buffer, "USER anonymous") == 0)
                    break;
                write(clientfd, MSG_530, 82);
            }
            write(clientfd, MSG_331, 29);
        }
    }
    printf("Terminating server.\n");
    close(serverfd);
    exit(0);
}