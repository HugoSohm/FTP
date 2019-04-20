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

void unknown_command(client_t *client)
{
    my_write(client->clientfd, MSG_500);
}

void close_client(int i, client_t *client, server_t *server)
{
    write(client->clientfd, MSG_221, 13);
    close(i);
    FD_CLR(i, &server->activefds);
}