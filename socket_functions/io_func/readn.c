# include "unp.h"


/**
 * readn - Read at most n bytes from buffer
 * @fd: file descriptor to socket stream
 * @buff - pointer to buffer to store bytes
 * @nbytes - number of nytes to copy to buffer
 * Return: number of bytes copied
 */

ssize_t readn(int fd, void *buff, size_t nbytes)
{
	size_t n_left;
	size_t n_read;
	char *ptr;

	n_left = nbytes;
	n_read = 0;
	ptr = buff;
	while (n_left > 0)
	{
		n_read = read(fd, ptr, n_left);
		if (n_read < 0)
		{
			if (errno == EINTR)
				n_read = 0;
			else
				return (n_read);
		} else if (n_read == 0)
			break;
		n_left -= n_read;
		ptr += n_read;
	}
	return (nbytes - n_left);
}
