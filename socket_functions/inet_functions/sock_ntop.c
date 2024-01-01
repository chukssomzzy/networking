# include "unp.h"

/**
 * sock_ntop - convert network address bit to host and port in a
 * protocol independent manner.
 * @addrptr: generic address structure used to know the protocol address
 * @addrlen: socket address length
 * Return: the converted string in the format of "<IP_ADDRESS>.<PORT> else NULL
 */


char *sock_ntop(struct sockaddr *addrptr, socklen_t __attribute__((unused))
		addrlen)
{
	char portstr[7];
	static char str[128];

	switch (addrptr->sa_family)
	{
		case (AF_INET):
			{
				struct sockaddr_in *addr = (struct sockaddr_in *) addrptr;
				uint16_t tmpp;

				if (inet_ntop(addr->sin_family, &addr->sin_addr, str, sizeof(str)))
				{
					tmpp = ntohs(addr->sin_port);
					if (tmpp)
					{
						snprintf(portstr, sizeof(portstr), ".%d", tmpp);
						strcat(str, portstr);
						return (str);
					}
				}
				return (NULL);
			}
	}
	errno = EAFNOSUPPORT;
	return (NULL);
}
