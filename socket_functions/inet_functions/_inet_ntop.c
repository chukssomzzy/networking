# include "unp.h"
# include <errno.h>
# include <netinet/in.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>


/**
 * _inet_ntop - from network to presentatiion
 * @family: address family
 * @addrptr: pointer to address structure
 * @strptr: pointer to string characters
 * @len: The number of byte allocated to strptr
 * Return: The address or NULL on failure
 */

const char *_inet_ntop(int family, const void *addrptr, char *strptr,
		size_t len)
{
	const uint8_t *p;
	char temp[INET_ADDRSTRLEN];

	if (family == AF_INET)
	{
		p = (u_char *) addrptr;

		snprintf(temp, INET_ADDRSTRLEN, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
		if (len < INET_ADDRSTRLEN)
		{
			errno = ENOSPC;
			return (NULL);
		}
		strcpy(strptr, temp);
		return (strptr);
	}
	errno = EAFNOSUPPORT;
	return (NULL);
}
