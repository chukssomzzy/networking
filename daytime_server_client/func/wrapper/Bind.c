# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>

/**
 * Bind - bind a socket to an addr and port combo
 * @sockfd: file descriptor to bind socket to
 * @servaddr: The servaddr to bind file descriptor on
 * @addrlen: len of servaddr
 */

void Bind(int sockfd, struct sockaddr *servaddr, size_t addrlen)
{
	int n;

	n = bind(sockfd, servaddr, addrlen);
	if (n < 0)
	{
		perror("Bind error");
		exit(EXIT_FAILURE);
	}
}
