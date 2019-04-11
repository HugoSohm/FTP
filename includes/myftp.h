/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** myftp.h
*/

#ifndef MYFTP_H
#define MYFTP_H

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 4097

typedef int bool;
#define true 1
#define false 0

#define USAGE "USAGE: ./server port\n\tport\tis the port number on which the server socket listens\n"
#define MSG_200 "200 Command okay.\n"
#define MSG_214 "214 Help message.\n"
#define MSG_220 "220 Hello\n"
#define MSG_221 "221 Goodbye.\n"
#define MSG_227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n"
#define MSG_230 "230 Login successful.\n"
#define MSG_331 "331 Please specify password.\n"
#define MSG_500 "500 Unknown command.\n"
#define MSG_530 "530 Please login with USER and PASS.\n"
#define MSG_550 "550 Requested action not taken.\n"

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
    char *newPath;
    bool is_root;
    int mode;
} client_t;

int main(int argc, char **argv);
int myftp(int port, char *path);
void epurStr(char *str);
char *upCase(char *str);
void error(char *msg);

void my_cwd(char *new_path, int clientfd);
void my_exit(char *msg, int value);
void my_write(int fd, char *str);
void my_dele(client_t client);
void my_help(client_t client);
void my_pasv(client_t client);
void my_cdup(client_t client);
void my_noop(client_t client);
void my_port(client_t client);
void my_list(client_t client);
void my_pwd(client_t client);

void checkPassword(client_t client, server_t server);
void checkUsername(client_t client, server_t server);
void checkCommands(client_t client, server_t server);
void closeServer(client_t client, server_t server);
void serverLoop(client_t client, server_t server);
void unknownCommand(client_t client);

server_t initServer();
client_t initClient();

#endif