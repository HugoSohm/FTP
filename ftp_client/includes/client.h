/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** client.h
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 128

int client(char *address, int port);
int main(int argc, char **argv);
void epur_str(char *str);
void error(char *msg);

#endif