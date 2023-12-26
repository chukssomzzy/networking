# include <stdio.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <stdlib.h>

/**
 * Listen - wrapper around listen
 * @sockfd: file descriptor of a binded socket to listen on
 * @nq: number of client to put on the listen queue
 * If LISTENQ is defined in tge environment, it value is used for backlog
 */

void Listen(int sockfd, int nq)
{
	int n;
	char *strptr;

	if ((strptr = getenv("LISTENQ")) != NULL)
		nq = atoi(strptr);

	n = listen(sockfd, nq);
	if (n < 0)
	{
		perror("listen errror");
		exit(EXIT_FAILURE);
	}
}
