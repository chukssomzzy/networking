# include "unp.h"
#include <stdio.h>
static void cli_echo(FILE *, uint8_t);

/**
 * main - echo client reads a line from standard input and
 * sends it to the server on network input
 * @argc: number of argument in argument vector
 * @argv: argument vector
 * Return: 1 (failure) 0 (success)
 */

int main(int argc, char **argv)
{
	uint8_t connfd[5], i;
	struct sockaddr_in sa;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <ip_address>\n", argv[0]);
		exit(1);
	}

	for (i = 0; i < 5; i++)
	{
	connfd[i] = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&sa, sizeof(sa));

	sa.sin_family = AF_INET;
	sa.sin_port = htons(SERV_PORT);
	inet_pton(sa.sin_family, argv[1], &(sa.sin_addr));

	Connect(connfd[i], (struct sockaddr *) &sa, sizeof(sa));
	}

	cli_echo(stdin, connfd[0]);
	exit(0);
}

/**
 * cli_echo - Reads a line from standard input then outputs it to network
 * then read a line from network input then print it on standard output
 * @stdin: standard input stream
 * @connfd: connection socket
 */

void cli_echo(FILE *stdin, uint8_t connfd)
{
	char buf[MAXLINE];
	int16_t len;

	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		len = writen(connfd, buf, strlen(buf));
		if (len <= 0)
			return;
		len = readline(connfd, buf, MAXLINE);
		if (len <= 0)
			return;
		Fputs(buf, stdout);
	}
}
