/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands3.c
*/

#include "myftp.h"

void my_cwd(char *pathname, client_t *client)
{
    char path[BUFSIZE];

    sprintf(path, "%.4096s", pathname);
    if (!pathname || chdir(path) == -1) {
        my_write(client->clientfd, MSG_550);
        return;
    }
    my_write(client->clientfd, MSG_250);
}

void my_pwd(client_t *client)
{
    char pathname[SIZE];
    char c = 34;

    if (getcwd(pathname, sizeof(pathname)) != NULL) {
        my_write(client->clientfd, "257 ");
        write(client->clientfd, &c, 1);
        my_write(client->clientfd, pathname);
        write(client->clientfd, &c, 1);
        my_write(client->clientfd, "\n");
    } else
        my_write(client->clientfd, MSG_550);
}