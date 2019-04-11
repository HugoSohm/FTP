/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** server.c
*/

#include "../includes/myftp.h"

int myftp(int port, char *path)
{
    server_t server = initServer(port, path);
    client_t client = initClient(port, path);

    if (server.serverfd < 0)
        perror("ERROR opening socket");

    setsockopt(server.serverfd, SOL_SOCKET, SO_REUSEADDR,
    (const void *)&server.optval , sizeof(int));

    if (bind(server.serverfd, (struct sockaddr *)&server.serverSock,
    sizeof(server.serverSock)) == -1)
        perror("Error on binding");

    if (listen(server.serverfd, 10) == -1)
        perror("Error on listen");

    serverLoop(client, server);
    closeServer(client, server);
}

void serverLoop(client_t client, server_t server)
{
    while (42) {
        FD_ZERO(&server.readfds);
        FD_SET(server.serverfd, &server.readfds);
        FD_SET(0, &server.readfds);

        if (select(server.serverfd + 1, &server.readfds, NULL, NULL, NULL)
            == -1)
            perror("Error in select");

        if (FD_ISSET(0, &server.readfds))
            printf("Writing in server\n");

        if (FD_ISSET(server.serverfd, &server.readfds)) {
            client.clientfd = accept(server.serverfd, (struct sockaddr *)
            &client.clientSock, (socklen_t*)&client.clientSockSize);

            if (inet_ntop(AF_INET, &client.clientSock.sin_addr.s_addr,
            server.infoConnect, sizeof(server.infoConnect)) != NULL)
                printf("Connection from %s:%d\n", server.infoConnect,
                ntohs(client.clientSock.sin_port));
            my_write(client.clientfd, MSG_220);

            if (client.clientfd == -1)
                perror("Error on accept");

            checkUsername(client, server);
            checkPassword(client, server);
            checkCommands(client, server);
        }
    }
}