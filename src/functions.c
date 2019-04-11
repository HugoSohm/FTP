/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** functions.c
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

char *upCase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

void epurStr(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    while (str[i]) {
        if (str[i] != ' ' && str[i] != '\t')
            str[j++] = str[i++];
        else {
            str[j++] = ' ';

            while (str[i] == ' ' || str[i] == '\t')
                i++;
        }
        str[j] = 0;

        if (str[j - 1] == ' ')
            str[j - 1] = '\0';
    }
}