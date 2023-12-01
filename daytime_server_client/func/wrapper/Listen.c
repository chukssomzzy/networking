# include <stdio.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <stdlib.h>

/**
 * Listen - wrapper around listen
 * @sockfd: file descriptor of a binded socket to listen on
 * @nq: number of client to put on the listen queue
 */

void Listen(int sockfd, int nq)
{
	int n;

	n = listen(sockfd, nq);
	if (n < 0)
	{
		perror("listen errror");
		exit(EXIT_FAILURE);
	}
}
