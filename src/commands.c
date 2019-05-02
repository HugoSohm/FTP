/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands.c
*/

#include "myftp.h"

void my_pasv(client_t *client)
{
    my_write(client->clientfd, MSG_227);
}

void my_cdup(client_t *client)
{
    my_cwd("..", client);
}

void my_dele(client_t *client)
{
    my_write(client->clientfd, MSG_550);
}

void my_help(client_t *client)
{
    my_write(client->clientfd, MSGH);
    my_write(client->clientfd, MSG_214);
}