#include <stdio.h>
#include <stdlib.h>
# include <sys/socket.h>

/**
 * Connect - wrapper function for connect
 * @sockfd: filedescriptor to open unix socket
 * @servaddr: address to connect
 * @addr_len: address length
 */

void Connect(int sockfd, struct sockaddr *servaddr, size_t addr_len)
{
	if (connect(sockfd, servaddr, addr_len) < 0)
	{
		perror("connect error");
		exit(EXIT_FAILURE);
	}

}
