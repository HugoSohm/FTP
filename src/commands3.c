/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands3.c
*/

#include "../includes/myftp.h"

void my_cwd(char *new_path, int clientfd)
{
    char path[BUFSIZE];

    sprintf(path, "%.4096s", new_path);
    if (!new_path || chdir(path) == -1) {
        my_write(clientfd, MSG_220);
        return;
    }
    my_write(clientfd, MSG_220);
}

void my_pwd(client_t client)
{
    char c = 34;
    char path_pwd[BUFSIZE];

    if (getcwd(path_pwd, sizeof(path_pwd)) != NULL) {
        my_write(client.clientfd, "257 ");
        write(client.clientfd, &c, 1);
        my_write(client.clientfd, path_pwd);
        write(client.clientfd, &c, 1);
        my_write(client.clientfd, "\n");
    } else
        my_write(client.clientfd, MSG_550);
}

void unknownCommand(client_t client)
{
    my_write(client.clientfd, MSG_500);
}

void closeServer(client_t client, server_t server)
{
    write(client.clientfd, MSG_221, 13);
    close(server.serverfd);
    exit(0);
}