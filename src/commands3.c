/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** commands3.c
*/

#include "../includes/myftp.h"

void my_cwd(char *buffer, client_t client)
{
    char path[BUFSIZE];
    char *new_path = malloc(sizeof(char) * (strlen(buffer) + 1 - 4));
    int i = 0;
    int j = 1;

    for (; buffer[i] && buffer[i] != '\r' && buffer[i] != '\n' && buffer[i] != ' '; i++);
    
    for (;buffer[i+j]; j++)
        new_path[j - 1] = buffer[i + j];

    sprintf(path, "%.4096s", new_path);
    if (!new_path || chdir(path) == -1) {
        my_write(client.clientfd, MSG_550);
        return;
    }
    my_write(client.clientfd, MSG_250);
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

void my_list(char *pathname, client_t client)
{
    FILE *fp;
    char path[SIZE];

    if (client.mode == 0) {
        my_write(client.clientfd, MSG_425);
        return;
    }

    if (!pathname)
        sprintf(path, "ls -l .");
    else
        sprintf(path, "ls -l %.4096s", pathname);
    fp = popen(path, "r");
    
    while (fgets(path, BUFSIZE, fp) != NULL)
        my_write(client.clientfd, path);
    pclose(fp);
    my_write(client.clientfd, MSG_250);
}

void unknownCommand(client_t client)
{
    my_write(client.clientfd, MSG_500);
}