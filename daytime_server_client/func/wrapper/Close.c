# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/**
 * Close - Wrapper around the system close function
 * @fd: the fd to close
 */

void Close(int fd)
{
	int n;

	n = close(fd);
	if (n < 0)
	{
		perror("close error");
		exit(EXIT_FAILURE);
	}
}
