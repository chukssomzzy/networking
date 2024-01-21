# include "unp.h"
# include <sys/resource.h>
static void str_echo(uint8_t);
static void sig_chld(int);
static void chld_hand(int);
/**
 * main - echo server
 * @argc: Number of arguments in argument vector
 * @argv: argument vector
 * Return: 1 success 0 failure
 */

int main(int __attribute__((unused))argc, char __attribute__((unused))**argv)
{
	uint8_t lsfd, connfd;
	struct sockaddr_in sa, ca;
	socklen_t calen = MAXSOCKLEN;

	lsfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&sa, sizeof(sa));
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(SERV_PORT);
	sa.sin_family = AF_INET;

	Bind(lsfd, (struct sockaddr *) &sa, sizeof(sa));

	Listen(lsfd, LISTENQ);
	Signal(SIGCHLD, sig_chld);
	for ( ;; )
	{
		Signal(SIGTERM, chld_hand);
		connfd = Accept(lsfd, (struct sockaddr *) &ca, &calen);
		printf("Connected to client on %s\n",
				sock_ntop((struct sockaddr *) &ca, calen));
		if (fork() == 0)
		{
			close(lsfd);
			str_echo(connfd);
			close(connfd);
			exit(0);
		}
	}
	exit(0);
}

/**
 * str_echo - Read a line from network input write the line back to the clienr
 * connect on the socket deacriptor
 * @connfd: socket descriptor for connection
 */

void str_echo(uint8_t connfd)
{
	char buf[MAXLINE];
	int32_t len;

	while ((len = readline(connfd, buf, MAXLINE)) > 0)
	{
		len = writen(connfd, buf, strlen(buf));
		if (len < 0)
			return;
	}
}

/**
 * sig_chld - wait for a child to terminate
 * @signo: signal received
 */

void sig_chld(int __attribute__((unused)) signo)
{
	pid_t pid;
	int stat;

	while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("Child %i terminated\n", pid);
}

/**
 * chld_hand - closes all child file descriptor
 * @signo: Signal received
 */

void chld_hand(int __attribute__((unused)) signo)
{
	struct rlimit *lim = NULL;
	uint16_t fd;

	if (getrlimit(RLIMIT_NOFILE, lim) < 0)
		err_quit("getrlimit error");

	for (fd = 0; fd < lim->rlim_cur; fd++)
		close(fd);
}
