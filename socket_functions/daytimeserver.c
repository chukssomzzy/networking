# include "unp.h"
# include <time.h>

/**
 * main - daytime server
 * @argc: The number argument in argument vector
 * @argv: argument vector
 * Return: 0 (success) 1 (failure)
 */

int main(int __attribute__((unused)) argc, char **__attribute__((unused))argv)
{
	struct sockaddr_in lsaddr, connaddr;
	int lsfd, connfd = 0;
	socklen_t addrlen, connaddrlen = 0;
	char strbuf[MAXLINE];
	time_t tick;

    lsfd = Socket(AF_INET, SOCK_STREAM, 0);

	lsaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	lsaddr.sin_port = htons(1030);
	lsaddr.sin_family = AF_INET;

	addrlen = sizeof(lsaddr);
	Bind(lsfd, (struct sockaddr *) &lsaddr, addrlen);

	Listen(lsfd, LISTENQ);

	while (1)
	{
		connfd = Accept(lsfd, (SA *) &connaddr, &connaddrlen);
        printf("Connected to %s on port %i\n",
				inet_ntop(AF_INET, &connaddr, strbuf, connaddrlen),
				ntohs(connaddr.sin_port));
	   tick = time(NULL);
	   snprintf(strbuf, sizeof(strbuf), "%.24s\r\n", ctime(&tick));
	   Write(connfd, strbuf, strlen(strbuf));
	   Close(connfd);
	}
}
