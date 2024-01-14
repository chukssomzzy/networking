# include "unp.h"


/**
 * Accept - wrapper around the accept function
 * @listenfd: the filedescriptor to check for cnnected client
 * @servaddr: address to listen on
 * @addrlen: the len of the addr to listen on
 * Return: the filedescriptor of the socket that wants to connect
 */

int Accept(int listenfd, struct sockaddr *servaddr, socklen_t *addrlen)
{
	int fd;

	while ((fd = accept(listenfd, (struct sockaddr *) servaddr, addrlen)) < 0)
		if (errno == EINTR)
		{
			continue;
		} else
		{
			perror("accept error");
			exit(EXIT_FAILURE);
		}
	return (fd);
}
