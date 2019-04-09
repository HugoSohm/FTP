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
#include <ctype.h>

#define BUFSIZE 1024

#define MSG_331 "331 Please specify password.\n"
#define MSG_530 "530 Please login with USER and PASS.\n"
#define MSG_220 "220 Hello\n"
#define MSG_230 "230 Login successful.\n"
#define MSG_221 "221 Goodbye.\n"

typedef struct server_s {
    struct sockaddr_in serverSock;
    char infoConnect[INET_ADDRSTRLEN];
    char buffer[BUFSIZE];
    int serverfd;
    int optval;
    int n;
    fd_set readfds;
} server_t;

typedef struct client_s {
    struct sockaddr_in clientSock;
    int clientSockSize;
    int clientfd;
} client_t;

int main(int argc, char **argv);
void epur_str(char *str);
void error(char *msg);
int myftp(int port, char *path);
char *upCase(char *str);
void closeServer(client_t clientfd, server_t serverfd);

server_t initServer();
client_t initClient();

#endif