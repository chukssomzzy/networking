# include "unp.h"

/**
 * readline - read a line from sock stream
 * @fd: file descriptor of sock stream
 * @buff: Buff to write line to
 * @maxlen: Length of buffer
 * Return: the number of bytes read
 */

ssize_t readline(int fd, void *buff, size_t maxlen)
{
	char c, *ptr;
	ssize_t n, rd;

	rd = 0;
	ptr = buff;
	for (n = 0; n < (ssize_t) maxlen; n++)
	{
		rd = _read(fd, &c);
		if (rd == 1)
		{
			*ptr++ = c;
			if (c == '\n')
			{
				n++;
				break;
			}
		}
		else if (rd == 0)
		{
			if (n == 0)
				return (0);
			break;
		}
		else
			return (-1);
	}

	*ptr = '\0';
	return (n);
}
