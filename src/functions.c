/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** functions.c
*/

#include "../includes/myftp.h"

char *splitArg(char *arg)
{
    char *pathname = malloc(sizeof(char) * (strlen(arg) + 1 - 4));
    int i = 0;
    int j = 1;

    for (; arg[i] && arg[i] != '\r' && arg[i] != '\n' && arg[i] != ' '; i++);

    for (;arg[i+j]; j++)
        pathname[j - 1] = arg[i + j];
    return (pathname);
}

char *lowCase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
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