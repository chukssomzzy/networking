# include "unp.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>


/**
 * main - implements daytime server
 * @argc: number of argument string in argument vector
 * @argv: argument vector
 * Return: 0 success and 1 failure
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{

	int listenfd, connfd;
	sockaddr_in_t servaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1030);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);
	for ( ; ; )
	{
		connfd = Accept(listenfd, (SA *) NULL, NULL);

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		Write(connfd, buff, strlen(buff));

		Close(connfd);
	}
	exit(EXIT_SUCCESS);
}
