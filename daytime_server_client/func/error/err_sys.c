# include <stdio.h>
# include <stdlib.h>

/**
 * err_quit - print error and quit
 * @err_str: error to print before quit
 */

void err_sys(const char *err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}
