#include <stdlib.h>
# include <stdio.h>
#include <sys/socket.h>

/**
 * Socket - wrapper function around socket
 * @family: the protocol family to open filedescriptor for
 * @type: socket type
 * @protocol: use to specify protocol to use in a multiprotocol
 * family and sock type
 * Return: a file descriptor to the endpoint created for communication
 */

int Socket(int family, int type, int protocol)
{
	int n;

	n  = socket(family, type, protocol);
	if (n < 0)
	{
		perror("socket error");
		exit(EXIT_FAILURE);
	}
	return (n);
}
