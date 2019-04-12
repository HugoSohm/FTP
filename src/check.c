/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** check.c
*/

#include "../includes/myftp.h"

void checkUsername(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(lowCase(server.buffer), "user anonymous", 14) == 0) {
            write(client.clientfd, MSG_331, 29);
            return;
        } else if (strncmp(lowCase(server.buffer), "quit", 4) == 0)
            closeClient(client, server);
        write(client.clientfd, MSG_530, 37);
    }
}

void checkPassword(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(lowCase(server.buffer), "pass", 4) == 0) {
            write(client.clientfd, MSG_230, 22);
            return;
        } else if (strncmp(lowCase(server.buffer), "quit", 4) == 0)
            closeClient(client, server);
        write(client.clientfd, MSG_331, 29);
    }
}

void checkCommands(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(lowCase(server.buffer), "cwd", 3) == 0)
            my_cwd(splitArg(server), client);
        else if (strncmp(lowCase(server.buffer), "cdup", 4) == 0)
            my_cdup(client);
        else if (strncmp(lowCase(server.buffer), "dele", 4) == 0)
            my_dele(client);
        else if (strncmp(lowCase(server.buffer), "list", 4) == 0)
            my_list(splitArg(server), client);
        else if (strncmp(lowCase(server.buffer), "port", 4) == 0)
            my_port(client);
        else if (strncmp(lowCase(server.buffer), "pwd", 3) == 0)
            my_pwd(client);
        else if (strncmp(lowCase(server.buffer), "noop", 4) == 0)
            my_noop(client);
        else if (strncmp(lowCase(server.buffer), "pasv", 4) == 0)
            my_pasv(client);
        else if (strncmp(lowCase(server.buffer), "help", 4) == 0)
            my_help(client);
        else if (strncmp(lowCase(server.buffer), "quit", 4) == 0)
            closeClient(client, server);
        else
            unknownCommand(client);
    }
}