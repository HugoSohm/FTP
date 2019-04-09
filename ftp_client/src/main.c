/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** main.c
*/

#include "../includes/client.h"

void help()
{
    printf("USAGE: ./client address port\n");
    printf("\taddress\tis the addres on which the server is connected\n");
    printf("\tport\tis the port number on which the server socket listens\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        help();
    else if (argc == 3)
        client(argv[1], atoi(argv[2]));
    else {
        help();
        return (84);
    }
    return (0);
}