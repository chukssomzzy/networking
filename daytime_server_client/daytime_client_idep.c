# include "unp.h"
# include <netdb.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include <sys/socket.h>


/**
 * main - daytime client
 * @argc: the number of argument string in argument vector
 * @argv: argument vector
 * Return: 0 success and 1 failure
 */

int main(int argc, char **argv) {
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct  addrinfo *servaddr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <IPaddrress>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (getaddrinfo(argv[1], "13", NULL, &servaddr) != 0)
		err_quit("check hostname and try again");
    while (servaddr)
		if ((sockfd = socket(servaddr->ai_family, servaddr->ai_socktype, servaddr->ai_protocol)) < 0)
				servaddr = servaddr->ai_next;
		else
			break;
	if (!servaddr)
	{
		freeaddrinfo(servaddr);
		fprintf(stderr, "Daytime server not started at %s, %i\n", argv[1], 13);
		exit(EXIT_FAILURE);
	}
	if (connect(sockfd, servaddr->ai_addr, servaddr->ai_addrlen) < 0)
		err_quit("connection error");
	freeaddrinfo(servaddr);
	while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = '\0';
		if (fputs(recvline, stdout) == EOF)
			err_quit("fputs error");
	}
	if (n < 0)
	{
		fprintf(stderr, "read error");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}