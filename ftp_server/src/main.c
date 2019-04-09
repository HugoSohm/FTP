/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** main.c
*/

#include "../includes/server.h"

void help(void)
{
    printf("USAGE: ./server port\n");
    printf("\tport\tis the port number on which the server socket listens\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        help();
    else if (argc == 3)
        myftp(atoi(argv[1]), argv[2]);
    else {
        help();
        return (84);
    }
    return (0);
}