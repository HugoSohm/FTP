/*
** EPITECH PROJECT, 2018
** NWP_myftp_2018
** File description:
** client.c
*/

#include "../includes/client.h"

int client(char *address, int port)
{
	struct sockaddr_in clientSock;
    char buffer[BUFSIZE];
    char serverAnswer[256];
	int n = 0;
	int serverfd;

	serverfd = socket(AF_INET, SOCK_STREAM, 0);

	clientSock.sin_port = htons(port);
    clientSock.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientSock.sin_family = AF_INET;

	if (connect(serverfd, (struct sockaddr*)&clientSock, sizeof(clientSock)) == -1)
        perror("Error connecting to the server");

    memset(buffer, '\0', BUFSIZE);

    if (read(serverfd, buffer, BUFSIZE) != -1)
		buffer[strlen(buffer)-1] = '\0';
    	printf("%s\n", buffer);
		printf("NAME : ");
		fflush(stdout);

	while (1) {
        bzero(buffer, sizeof(buffer));
		fgets(buffer, BUFSIZE, stdin);
		write(serverfd, buffer, sizeof(buffer));
	}
	return 0;
}