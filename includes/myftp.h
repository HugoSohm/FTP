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
#define SIZE 4103

typedef int bool;
#define true 1
#define false 0

#define H1 "USAGE: ./server port\n"
#define H2 "\tport\tis the port number on which the server socket listens\n"
#define H3 "\tpath\tis the path to the home directory for the Anonymous user\n"
#define MSG_NEWUSER "New user connected from host %s, port %d.\n"
#define MSGH " CDUP CWD DELE LIST NOOP PASS PASV PORT PWD QUIT RETR STOR USER\n"
#define MSG_200 "200 Command okay.\n"
#define MSG_214 "214 Help message.\n"
#define MSG_220 "220 Hello\n"
#define MSG_221 "221 Goodbye.\n"
#define MSG_227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n"
#define MSG_230 "230 Login successful.\n"
#define MSG_250 "250 Directory successfully changed.\n"
#define MSG_331 "331 Please specify password.\n"
#define MSG_425 "425 Can't open data connection.\n"
#define MSG_500 "500 Unknown command.\n"
#define MSG_503 "503 Login with USER first.\n"
#define MSG_530 "530 Please login with USER and PASS.\n"
#define MSG_530_2 "530 Login incorrect.\n"
#define MSG_550 "550 Failed to change directory.\n"

typedef struct server_s {
    struct sockaddr_in serverSock;
    char infoConnect[INET_ADDRSTRLEN];
    char buffer[BUFSIZE];
    int serverfd;
    int optval;
    fd_set readfds;
    fd_set activefds;
} server_t;

typedef struct client_s {
    struct sockaddr_in clientSock;
    int clientsock_size;
    int clientfd;
    int is_log;
    int is_user;
    char *username;
    int mode;
} client_t;

int main(int argc, char **argv);
int myftp(int port, char *path);
char *remove_less(char *str);
char *split_arg(char *arg);
char *low_case(char *str);

void my_cwd(char *buffer, client_t *client);
void my_exit(char *msg, int value);
void my_write(int fd, char *str);
void my_dele(client_t *client);
void my_help(client_t *client);
void my_pasv(client_t *client);
void my_cdup(client_t *client);
void my_noop(client_t *client);
void my_port(client_t *client);
void my_pwd(client_t *client);

void check(int i, client_t *client, server_t *server);
void check_commands(int i, client_t *client, server_t *server);
void check_login(int i, client_t *client, server_t *server);
void check_username(char *username, client_t *client);
void check_password(char *password, client_t *client);

void close_client(int i, client_t *client, server_t *server);
void server_loop(client_t *client, server_t *server);
void unknown_command(client_t *client);

server_t *init_server();
client_t *init_client();

#endif