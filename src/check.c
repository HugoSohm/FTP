/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** check.c
*/

#include "../includes/myftp.h"

void check(int i, client_t *client, server_t *server)
{
    bzero(server->buffer, BUFSIZE);
    memset(server->buffer, 0, BUFSIZE);
    read(client->clientfd, server->buffer, BUFSIZE);

    if (client->isLog == 0)
        checkLogin(i, client, server);
    else if (client->isLog == 1)
        checkCommands(i, client, server);
}

void checkUsername(char *username, client_t *client)
{
    if (strncmp(username, "anonymous", 9) == 0)
        client->isUser = 2;
    else
        client->isUser = 1;
    write(client->clientfd, MSG_331, 29);
}

void checkPassword(char *password, client_t *client)
{
    if (client->isUser == 1) {
        write(client->clientfd, MSG_530_2, 21);
        client->isUser = 0;
    } else if (client->isUser == 2) {
        write(client->clientfd, MSG_230, 22);
        client->isLog = 1;
    } else
        write(client->clientfd, MSG_503, 27);
}

void checkLogin(int i, client_t *client, server_t *server)
{
    if (strncmp(lowCase(server->buffer), "user", 4) == 0)
        checkUsername(lowCase(splitArg(server->buffer)), client);
    else if (strncmp(lowCase(server->buffer), "pass", 4) == 0)
        checkPassword(lowCase(splitArg(server->buffer)), client);
    else if (strncmp(lowCase(server->buffer), "quit", 4) == 0)
        closeClient(i, client, server);
    else
        write(client->clientfd, MSG_530, 37);
}

void checkCommands(int i, client_t *client, server_t *server)
{
    if (strncmp(lowCase(server->buffer), "cwd", 3) == 0)
        my_cwd(splitArg(server->buffer), client);
    else if (strncmp(lowCase(server->buffer), "list", 4) == 0)
        my_list(splitArg(server->buffer), client);
    else if (strncmp(lowCase(server->buffer), "cdup", 4) == 0)
        my_cdup(client);
    else if (strncmp(lowCase(server->buffer), "dele", 4) == 0)
        my_dele(client);
    else if (strncmp(lowCase(server->buffer), "port", 4) == 0)
        my_port(client);
    else if (strncmp(lowCase(server->buffer), "pwd", 3) == 0)
        my_pwd(client);
    else if (strncmp(lowCase(server->buffer), "noop", 4) == 0)
        my_noop(client);
    else if (strncmp(lowCase(server->buffer), "pasv", 4) == 0)
        my_pasv(client);
    else if (strncmp(lowCase(server->buffer), "help", 4) == 0)
        my_help(client);
    else if (strncmp(lowCase(server->buffer), "quit", 4) == 0)
        closeClient(i, client, server);
    else
        unknownCommand(client);
}