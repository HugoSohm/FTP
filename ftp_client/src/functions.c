/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** functions.c
*/

#include "../includes/client.h"

void epur_str(char *str)
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