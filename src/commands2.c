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