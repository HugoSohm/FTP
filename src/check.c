/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** check.c
*/

#include "myftp.h"

void check(int i, client_t *client, server_t *server)
{
    bzero(server->buffer, BUFSIZE);
    memset(server->buffer, 0, BUFSIZE);
    read(client->clientfd, server->buffer, BUFSIZE);

    if (client->is_log == 0)
        check_login(i, client, server);
    else if (client->is_log == 1)
        check_commands(i, client, server);
}

void check_username(char *username, client_t *client)
{
    if (strncmp(username, "anonymous", 9) == 0)
        client->is_user = 2;
    else
        client->is_user = 1;
    my_write(client->clientfd, MSG_331);
}

void check_password(char *password, client_t *client)
{
    if (client->is_user == 1) {
        write(client->clientfd, MSG_530_2, 21);
        client->is_user = 0;
    } else if (client->is_user == 2) {
        write(client->clientfd, MSG_230, 22);
        client->is_log = 1;
    } else
        my_write(client->clientfd, MSG_503);
}

void check_login(int i, client_t *client, server_t *server)
{
    if (strncmp(low_case(server->buffer), "user", 4) == 0)
        check_username(low_case(split_arg(server->buffer)), client);
    else if (strncmp(low_case(server->buffer), "pass", 4) == 0)
        check_password(low_case(split_arg(server->buffer)), client);
    else if (strncmp(low_case(server->buffer), "quit", 4) == 0)
        close_client(i, client, server);
    else
        my_write(client->clientfd, MSG_530);
}

void check_commands(int i, client_t *client, server_t *server)
{
    if (strncmp(server->buffer, "CWD", 3) == 0)
        my_cwd(remove_less(split_arg(server->buffer)), client);
    else if (strncmp(low_case(server->buffer), "cdup", 4) == 0)
        my_cdup(client);
    else if (strncmp(low_case(server->buffer), "dele", 4) == 0)
        my_dele(client);
    else if (strncmp(low_case(server->buffer), "port", 4) == 0)
        my_port(client);
    else if (strncmp(low_case(server->buffer), "pwd", 3) == 0)
        my_pwd(client);
    else if (strncmp(low_case(server->buffer), "noop", 4) == 0)
        my_noop(client);
    else if (strncmp(low_case(server->buffer), "pasv", 4) == 0)
        my_pasv(client);
    else if (strncmp(low_case(server->buffer), "help", 4) == 0)
        my_help(client);
    else if (strncmp(low_case(server->buffer), "quit", 4) == 0)
        close_client(i, client, server);
    else
        unknown_command(client);
}