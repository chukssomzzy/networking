# ifndef _UP_P_H
# define _UP_P_H
/* includes library */
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <netinet/in.h>
# include <unistd.h>
# include <unistd.h>
# include <errno.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in sockaddr_in_t;
/**
 * sockaddr_in - defines ip address and port number
 * @port: int of port number where to attach the server
 * @addr: host address for the server
 */

/** definitions **/
# define MAXLINE 4096
# define LISTENQ 1024
# define SERV_PORT 9877
# define MAXSOCKLEN 104

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
int _inet_aton(const char *, struct in_addr *);
char *_inet_pton(int, void *, char *, size_t);
char *sock_ntop(struct sockaddr *, socklen_t  __attribute__((unused)));
int sock_bind_wild(int sockfd, int family);
/** Return 0 if the addr are same else nonzero **/
int sock_cmp_addr(const struct sockaddr *addr1, const struct sockaddr *addr2, socklen_t len);
/** Return 0 if the port are the same **/
int sock_cmp_port(const struct sockaddr *addr1, const struct sockaddr *addr2, socklen_t len);
/** Return nonNegative Ip v4 or v6 port **/
int sock_get_port(const struct sockaddr *addr, socklen_t len);
char *sock_ntop_host(const struct sockaddr *addr, socklen_t len);
void sock_set_addr(const struct sockaddr *addr, socklen_t len, char *ptr);
void sock_set_port(const struct sockaddr *addr, socklen_t len, int port);
void sock_set_wild(const struct sockaddr *addr, socklen_t len);
/** Read n bytes from a socket to the buffer **/
ssize_t readn(int fd, void *buf, size_t nbytes);
/** Write n bytes to buffer from socket stream **/
ssize_t writen(int fd, void *buf, size_t nbytes);
/** readline from socket stream **/
ssize_t readline(int fd, void *buf, size_t maxbytes);
int _read(int , char *);
void Fputs(const char *, FILE *);
# endif
