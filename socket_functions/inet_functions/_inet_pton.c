# include "unp.h"
# include <strings.h>
# include <string.h>
# include <errno.h>


/**
 * _inet_pton - desired convert human readable ascii to network bits
 * @family: protocol family to convert
 * @strptr: Pointer seperating the string to convert
 * @addrptr: pointer to structure to write network bit
 * Return: 1 (success) 0 (convertion error) -1 (error)
 */

int _inet_pton(int family, const char *strptr, void *addrptr)
{
	struct in_addr in_val;

	if (family == AF_INET)
	{
		if (_inet_aton(strptr, &in_val))
		{
			memcpy(addrptr, &in_val, sizeof(struct in_addr));
			return (1);
		}

	}
	errno = EAFNOSUPPORT;
	return (-1);
}

/**
 * _inet_aton - convert ascii address to network bit
 * @strptr: pointer to address
 * @addrptr: pointer to store address
 * Return: 1 (failure) 0 (success)
 */

int _inet_aton(const char *strptr, struct in_addr *addrptr)
{
	uint32_t netw = 0;
	uint32_t temp = 0;
	char *strnum = {0};
	char *inetstr = {0};
	uint8_t bitnum = 32;

	inetstr = strdup(strptr);

	while ((strnum = strtok(inetstr, ".")))
	{
		temp = atoi(strnum);
		bitnum -= 8;
		netw = netw | (temp << (bitnum));
		inetstr = NULL;
		temp = 0;
	}
	if (!strnum && bitnum)
	{
		free(inetstr);
		return (0);
	}
	addrptr->s_addr = htonl(netw);
	free(inetstr);
	return (1);
}
