# include <stdio.h>
# include <stdlib.h>

/**
 * Fputs - wrapper around fget
 * @buf: buffer to read character from
 * @fp: file pointer
 */

void Fputs(const char *buf, FILE *fp)
{
	ssize_t len;

	len = fputs(buf, fp);
	if (len < 0)
	{
		perror("fputs error");
		exit(1);
	}
}
