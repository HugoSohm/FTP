/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** init.c
*/

#include "myftp.h"

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

    client->clientsock_size = sizeof(client->clientSock);
    client->is_log = 0;
    client->is_user = 0;

    return (client);
}