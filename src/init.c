/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** init.c
*/

#include "../includes/myftp.h"

server_t *init_server(int port, char *path)
{
    server_t *server = malloc(sizeof(server_t));

    server->serverfd = socket(AF_INET, SOCK_STREAM, 0);
    server->optval = 1;
    server->serverSock.sin_port = htons(port);
    server->serverSock.sin_addr.s_addr = htonl(INADDR_ANY);
    server->serverSock.sin_family = AF_INET;

    return (server);
}

client_t *init_client(int port, char *path)
{
    client_t *client = malloc(sizeof(client_t));
    client->clientSockSize = sizeof(client->clientSock);

    client->mode = 1;
    client->isLog = 0;
    client->isUser = 0;

    return (client);
}