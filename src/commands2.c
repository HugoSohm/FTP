/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands2.c
*/

#include "myftp.h"

void my_noop(client_t *client)
{
    my_write(client->clientfd, MSG_200);
}

void my_port(client_t *client)
{
    my_write(client->clientfd, MSG_200);
}