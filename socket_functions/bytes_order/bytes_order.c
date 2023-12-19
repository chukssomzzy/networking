# include "unp.h"

/**
 * main - check bytes order of the system it executed on
 * @argc: number of argument passed
 * @argv: pointer containing all arguments (argument vectors)
 * Return: 0 (success) 1 (failure)
 */

int main(int __attribute__ ((unused)) argc,
		char __attribute__ ((unused)) **argv)
{
	union {
		int16_t s;
		int8_t l[sizeof(int16_t)];
	} un;
	un.s = 0x0102;
	printf("Your architecture is: ");
	if (un.l[0] == 1 && un.l[1] == 2)
		printf("big-endian\n");
	else if (un.l[0] == 2 && un.l[1] == 1)
		printf("little-endian\n");
	else
		printf("unknown order\n");
	return (0);
}
