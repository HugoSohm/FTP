/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** functions.c
*/

#include "myftp.h"

char *split_arg(char *arg)
{
    char *pathname = malloc(sizeof(char) * (strlen(arg) + 1 - 4));
    int i = 0;
    int j = 1;

    for (; arg[i] && arg[i] != '\r' && arg[i] != '\n' && arg[i] != ' '; i++);

    for (;arg[i+j]; j++)
        pathname[j - 1] = arg[i + j];
    return (pathname);
}

char *low_case(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}

char *remove_less(char *str)
{
    int i = 0;

    while (str[i] != '\r' && str[i] != '\n' && str[i] != '\0')
        i++;
    str[i] = '\0';
    return (str);
}