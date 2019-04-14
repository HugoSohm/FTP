/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** server.c
*/

#include "../includes/myftp.h"

int myftp(int port, char *path)
{
    server_t *server = initServer(port, path);
    client_t *client = initClient(port, path);

    if (server->serverfd < 0)
        perror("ERROR opening socket");

    setsockopt(server->serverfd, SOL_SOCKET, SO_REUSEADDR,
    (const void *)&server->optval , sizeof(int));

    if (bind(server->serverfd, (struct sockaddr *)&server->serverSock,
    sizeof(server->serverSock)) == -1)
        perror("Error on binding");

    if (listen(server->serverfd, 1) < 0)
        perror("Error on listen");

    serverLoop(client, server);
}

void serverLoop(client_t *client, server_t *server)
{
    FD_ZERO(&server->activefds);
    FD_SET(server->serverfd, &server->activefds);

    while (42) {
        server->readfds = server->activefds;

        if (select(FD_SETSIZE, &server->readfds, NULL, NULL, NULL) < 0)
            perror("Error in select");

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &server->readfds)) {
                if (i == server->serverfd) {
                    client->clientfd = accept(server->serverfd,
                    (struct sockaddr *)&client->clientSock, (socklen_t *)
                    &client->clientSockSize);

                    if (client->clientfd < 0)
                        perror("Error in accept");
                    fprintf(stderr, "Server: connect from host %s, port %d.\n",
                    inet_ntoa(client->clientSock.sin_addr),
                    ntohs(client->clientSock.sin_port));
                    my_write(client->clientfd, MSG_220);
                    FD_SET(client->clientfd, &server->activefds);
                } else {
                    check(i, client, server);
                }
            }
        }
    }
}