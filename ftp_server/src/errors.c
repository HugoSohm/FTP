/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** errors.c
*/

#include "../includes/server.h"

void error(char *msg)
{
    perror(msg);
    exit(1);
}