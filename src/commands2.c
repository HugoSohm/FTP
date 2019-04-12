/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands2.c
*/

#include "../includes/myftp.h"

void my_noop(client_t client)
{
    my_write(client.clientfd, MSG_200);
}

void my_port(client_t client)
{
    my_write(client.clientfd, MSG_200);
}

void unknownCommand(client_t client)
{
    my_write(client.clientfd, MSG_500);
}

void closeClient(client_t client, server_t server)
{
    write(client.clientfd, MSG_221, 13);
    exit(0);
}