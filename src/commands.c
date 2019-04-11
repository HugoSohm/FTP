/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands.c
*/

#include "../includes/myftp.h"

void my_pasv(client_t client)
{
    client.mode = 1;
    my_write(client.clientfd, MSG_227);
}

void my_cdup(client_t client)
{
    my_cwd("..", client);
}

void my_dele(client_t client)
{
    if (client.is_root == false)
        my_write(client.clientfd, MSG_550);
}

void my_help(client_t client)
{
    my_write(client.clientfd, " CDUP CWD DELE LIST NOOP PASS PASV PORT ");
    my_write(client.clientfd, "PWD QUIT RETR STOR USER\n");
    my_write(client.clientfd, MSG_214);
}