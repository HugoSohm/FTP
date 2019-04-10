/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** init.c
*/

#include "../includes/server.h"

server_t initServer(int port, char *path)
{
    server_t server;

    server.serverfd = socket(AF_INET, SOCK_STREAM, 0);
    server.optval = 1;
    server.serverSock.sin_port = htons(port);
    server.serverSock.sin_addr.s_addr = htonl(INADDR_ANY);
    server.serverSock.sin_family = AF_INET;

    return (server);
}

client_t initClient(int port, char *path)
{
    client_t client;

    client.clientSockSize = sizeof(client.clientSock);
    client.clientSockSize = sizeof(client.clientSock);

    client.mode = 1;
    client.is_root = false;
    client.newPath = "./";

    return (client);
}