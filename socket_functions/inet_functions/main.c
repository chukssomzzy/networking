# include "unp.h"
# include <arpa/inet.h>
# include <stdio.h>

/**
 * main - convert ascii address to network bit
 * @argc: Number of argument in argument vector
 * @argv: pointers to argument vector
 * Return: 0 (success) 1 (failure)
 */

int main(int argc, char **argv)
{
	char *addr = argv[1];
	struct in_addr addrstr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <ip address>\n", argv[0]);
		return (1);
	}
	if (_inet_pton(AF_INET, addr, &addrstr))
	{
		addr = inet_ntoa(addrstr);
		printf("%s \n", addr);
		return (0);
	}
	return (1);
}
