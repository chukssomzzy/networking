# ifndef _UP_P_H
# define _UP_P_H
/* includes library */
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <netdb.h>
# include <unistd.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in sockaddr_in_t;
/**
 * sockaddr_in - defines ip address and port number
 * @port: int of port number where to attach the server
 * @addr: host address for the server
 */

/** definitions **/
# define MAXLINE 1024
# define LISTENQ 1024

/** Prototypes **/
void err_quit(const char *);
void err_sys(char *);
int Socket(int, int, int);
void Pthread_mutex_lock(pthread_mutex_t *);
int Connect(int, SA *, size_t);
void Bind(int, SA *, size_t);
int Accept(int, SA *, socklen_t *);
size_t Write(int, void *, size_t);
void Close(int fd);
void Listen(int, int);

# endif
