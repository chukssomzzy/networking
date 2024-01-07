# include "unp.h"

/**
 * writen - write at most n bytes to a socket stream
 * @fd: The file descriptor of the socket stream
 * @buff: Buff to write bytes from
 * @nbytes: number of bytes to write
 * Return: the number pf byte wrote to socket or -1 on error
 */

ssize_t writen(int fd, void *buff, size_t nbytes)
{
	size_t n_left;
	ssize_t n_writen;
	char  *ptr;

	n_left = nbytes;
	n_writen = 0;
	ptr = buff;
	while (n_left > 0)
	{
		n_writen = write(fd, ptr, n_left);
		if (n_writen < 0)
		{
			if (errno == EINTR)
				n_writen = 0;
			else
				return (n_writen);
		} else if (n_writen == 0)
			break;
		n_left -= n_writen;
		ptr += n_writen;
	}
	return (nbytes);
}
