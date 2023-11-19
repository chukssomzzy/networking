# include "unp.h"
#include <stdio.h>
#include <strings.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * main - start the excution of the program
 * @argc - length of argument vector
 * @argv - holds pointer to string pointer
 * return: 0 (sucesss) 1 (failure)
 */

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct  sockaddr_in servaddr;

    if (argc != 2)
	{
        fprintf(stderr, "usage: a.out <IPaddress>");
		exit(EXIT_FAILURE);
	}
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_quit("socket error");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if (inet_pton(AF_INET, argv[1], &(servaddr.sin_addr)) <= 0)
		err_quit("connect error");
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr.sin_addr)) < 0)
		err_quit("connect error");
	while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = '\0'; /* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_quit("fputs error");
	}
	if (n < 0)
		err_quit("read error");

	exit(0);
}
