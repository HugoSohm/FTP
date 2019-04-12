/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** tools.c
*/

#include "../includes/myftp.h"

void my_write(int fd, char *str)
{
    if (write(fd, str, strlen(str)) == -1)
        my_exit("Error : write", EXIT_FAILURE);
}

void my_exit(char *msg, int value)
{
    if (msg)
        fprintf(stderr, "%s\n", msg);
    exit(value);
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