/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands2.c
*/

#include "../includes/server.h"

void my_noop(client_t client)
{
    my_write(client.clientfd, MSG_200);
}

void my_port(client_t client)
{
    my_write(client.clientfd, MSG_200);
}

void my_list(client_t client)
{
    my_write(client.clientfd, "list\n");
}