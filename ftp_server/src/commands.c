/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands.c
*/

#include "../includes/server.h"

void my_cwd(char *new_path, int client_fd)
{
    char path[PATH_MAX];

    sprintf(path, "%.4096s", new_path);
    if (!new_path || chdir(path) == -1) {
        my_write(client_fd, MSG_220);
        return;
    }
    my_write(client_fd, MSG_220);
}