/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** server.c
*/

#include "../includes/server.h"

int myftp(int port, char *path)
{
    server_t server = initServer(port, path);
    client_t client = initClient(port, path);

    if (server.serverfd < 0)
        perror("ERROR opening socket");

    setsockopt(server.serverfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&server.optval , sizeof(int));

    if (bind(server.serverfd, (struct sockaddr *)&server.serverSock, sizeof(server.serverSock)) == -1)
        perror("Error on binding");
    
    if (listen(server.serverfd, 10) == -1)
        perror("Error on listen");

    while (42) {
        FD_ZERO(&server.readfds);
        FD_SET(server.serverfd, &server.readfds);
        FD_SET(0, &server.readfds);

        if (select(server.serverfd + 1, &server.readfds, NULL, NULL, NULL) == -1)
            perror("Error in select");

        if (FD_ISSET(0, &server.readfds))
            printf("Writing in server\n");

        if (FD_ISSET(server.serverfd, &server.readfds)) {
            client.clientfd = accept(server.serverfd, (struct sockaddr *)&client.clientSock, (socklen_t*)&client.clientSockSize);

            if (inet_ntop(AF_INET, &client.clientSock.sin_addr.s_addr, server.infoConnect,sizeof(server.infoConnect)) != NULL)
                printf("Connection from %s:%d\n", server.infoConnect, ntohs(client.clientSock.sin_port));
            write(client.clientfd, "220 Hello\n", 10);

            if (client.clientfd == -1)
                perror("Error on accept");

            while (42) {
                bzero(server.buffer, BUFSIZE);
                memset(server.buffer, 0, BUFSIZE);
                read(client.clientfd, server.buffer, BUFSIZE);
                server.buffer[strlen(server.buffer)-2] = '\0';

                if (strcmp(upCase(server.buffer), "USER ANONYMOUS") == 0)
                    break;
                else if (strcmp(server.buffer, "QUIT") == 0)
                    closeServer(client, server);
                write(client.clientfd, MSG_530, 37);
            }
            write(client.clientfd, MSG_331, 29);

            while (42) {
                bzero(server.buffer, BUFSIZE);
                memset(server.buffer, 0, BUFSIZE);
                read(client.clientfd, server.buffer, BUFSIZE);

                if (strncmp(upCase(server.buffer), "PASS", 4) == 0)
                    break;
                else if (strcmp(server.buffer, "QUIT") == 0)
                    closeServer(client, server);
                write(client.clientfd, MSG_331, 29);
            }
            write(client.clientfd, MSG_230, 22);
            closeServer(client, server);
        }
    }
    closeServer(client, server);
}