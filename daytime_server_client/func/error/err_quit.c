# include <stdio.h>
# include <stdlib.h>


/**
 * err_quit - print error and quit when
 * @err_str: err string to print before quitting
 */

void err_quit(char *err_str)
{
	fprintf(stderr, "%s\n", err_str);
	exit(EXIT_FAILURE);
}
