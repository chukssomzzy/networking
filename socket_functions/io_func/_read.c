# include "unp.h"


/**
 * _read - read and buffer from sock stream
 * @fd: file descriptor of sock stream
 * @ptr: buffer to store byte
 * Return: 1 (success) -1 (failure)
 */

int _read(int fd, char *ptr)
{
	static ssize_t rd;
	static char buf[MAXLINE];
	static char *bufptr;

	while (rd <= 0)
	{
		rd = read (fd, buf, sizeof(buf));
		if (rd < 0)
		{
			if (errno == EINTR)
			{
				rd = 0;
				continue;
			}
			else
				return (-1);
		} else
			return (0);
		bufptr = buf;
	}
	rd--;
	*ptr = *bufptr++;
	return (1);
}
