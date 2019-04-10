/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** check.c
*/

#include "../includes/server.h"

void checkCommands(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(upCase(server.buffer), "CWD", 4) == 0)
            my_cwd(client.newPath, client.clientfd);
        else if (strncmp(upCase(server.buffer), "CDUP", 4) == 0)
            my_cdup(client);
        else if (strncmp(upCase(server.buffer), "DELE", 4) == 0)
            my_dele(client);
        else if (strncmp(upCase(server.buffer), "LIST", 4) == 0)
            my_list(client);
        else if (strncmp(upCase(server.buffer), "PORT", 4) == 0)
            my_port(client);
        else if (strncmp(upCase(server.buffer), "PWD", 4) == 0)
            my_pwd(client);
        else if (strncmp(upCase(server.buffer), "NOOP", 4) == 0)
            my_noop(client);
        else if (strncmp(upCase(server.buffer), "PASV", 4) == 0)
            my_pasv(client);
        else if (strncmp(upCase(server.buffer), "HELP", 4) == 0)
            my_help(client);
        else if (strncmp(server.buffer, "QUIT", 4) == 0)
            closeServer(client, server);
        else {
            my_write(client.clientfd, server.buffer);
            unknownCommand(client);
        }
    }
}

void checkPassword(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(upCase(server.buffer), "PASS", 4) == 0) {
            write(client.clientfd, MSG_230, 22);
            return;
        } else if (strncmp(server.buffer, "QUIT", 4) == 0)
            closeServer(client, server);
        write(client.clientfd, MSG_331, 29);
    }
}

void checkUsername(client_t client, server_t server)
{
    while (42) {
        bzero(server.buffer, BUFSIZE);
        memset(server.buffer, 0, BUFSIZE);
        read(client.clientfd, server.buffer, BUFSIZE);

        if (strncmp(upCase(server.buffer), "USER ANONYMOUS", 14) == 0)
            break;
        else if (strncmp(server.buffer, "QUIT", 4) == 0)
            closeServer(client, server);
        write(client.clientfd, MSG_530, 37);
    }
    write(client.clientfd, MSG_331, 29);
}