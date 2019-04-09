/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** myftp.h
*/

#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

#define MSG_331 "331 Please specify password.\r\n"
#define MSG_530 "530 This FTP server is anonymous only.\r\nLogin failed, please enter a correct login\r\n"

int main(int argc, char **argv);
void epur_str(char *str);
void error(char *msg);
int server(int port);

#endif