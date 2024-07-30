#include <sft.h>

static int	ft_setup_recive(int *sockfd, struct sockaddr_in *srvaddr, int port)
{
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (*sockfd == -1)
		return (perror("socket"), 0);
	printf("TCP Socket created\n");
	memset(srvaddr, 0, sizeof(*srvaddr));
	srvaddr->sin_family = AF_INET;
	srvaddr->sin_addr.s_addr = htonl(INADDR_ANY);
	srvaddr->sin_port = htons(port);
	if (bind(*sockfd, (struct sockaddr *)srvaddr, sizeof(*srvaddr)) == -1)
		return (perror("bind"), 0);
	printf("IP Addres bound successfully\n");
	if (listen(*sockfd, 5) == -1)
		return (perror("listen"), 0);
	printf("Listening to incoming connections...\n");
	return (1);
}

static int	ft_recive_file(int connfd, int filefd, int sockfd)
{
	uint8_t	buff[1024];
	int		bytes_read;

	do
	{
		bytes_read = read(connfd, buff, sizeof(buff));
		if (bytes_read == -1)
			return (perror("read"),close(filefd), close(sockfd), 0);
		write(filefd, buff, bytes_read);
	} while (bytes_read > 0);
	return (1);
}

int	ft_recive(int port, char *filename)
{
	int					sockfd;
	int					connfd;
	int					filefd;
	struct sockaddr_in	srvaddr;
	struct sockaddr_in	cliaddr;
	socklen_t			len;

	if (!ft_setup_recive(&sockfd, &srvaddr, port))
		return (1);
	len = sizeof(struct sockaddr_in);
	connfd = accept(sockfd, (struct sockaddr *) &cliaddr, &len);
	if (connfd == -1)
		return (perror("accept"), 1);
	filefd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (filefd == -1)
		return (perror("open"), 1);
	printf("New connection accepted, receiving File...\n");
	ft_recive_file(connfd, filefd, sockfd);
	printf ("Done!\n");
	close(filefd);
	close(connfd);
	close(sockfd);
	return (0);
}
