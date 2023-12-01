# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/**
 * Write - wrapper around write
 * @fd: fd descriptor to write to
 * @buf: buffer to write from
 * @count: the number of item to write to the buffer
 * Return: the number of characters written to fd
 */

size_t Write(int fd, const void *buf, size_t count)
{
	ssize_t n;

	n = write(fd, buf, count);
	if (n < 0)
	{
		perror("write error");
		exit(EXIT_FAILURE);
	}
	return (n);
}
