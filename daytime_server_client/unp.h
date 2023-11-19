# ifndef _UP_P_H
# define _UP_P_H
/* includes library */
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>

typedef struct sockaddr SA;
/**
 * sockaddr_in - defines ip address and port number
 * @port: int of port number where to attach the server
 * @addr: host address for the server
 */

/** definitions **/
# define MAXLINE 1024

/** Prototypes **/
void err_quit(const char *);
# endif
