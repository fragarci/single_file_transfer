#include <sft.h>

static int	ft_setup_send(int *sockfd, struct sockaddr_in *srvaddr, char *ip, int port)
{
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (*sockfd == -1)
		return (perror("socket"), 0);
	printf("TCP Socket created\n");
	memset(srvaddr, 0, sizeof(*srvaddr));
	srvaddr->sin_family = AF_INET;
	srvaddr->sin_addr.s_addr = inet_addr(ip);
	srvaddr->sin_port = htons(port);
	return (1);
}

static int	ft_send_file(int filefd, int sockfd)
{
	uint8_t	buff[1024];
	int		bytes_read;

	do
	{
		bytes_read = read(filefd, buff, sizeof(buff));
		if (bytes_read == -1)
			return (perror("read"), close(filefd), close(sockfd), 0);
		write(sockfd, buff, bytes_read);
	} while (bytes_read > 0);
	return (1);
}

int ft_send(char *ip, int port, char *filename)
{
	struct sockaddr_in	srvaddr;
	int					sockfd;
	int					filefd;

	filefd = open(filename, O_RDONLY);
	if (filefd == -1)
		return (perror("open"), 1);
	ft_setup_send(&sockfd, &srvaddr, ip, port);
	if (connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) == -1)
		return  (perror("connect"), 1);
	printf("Connection established, transfering file...\n");
	if (!ft_send_file(filefd, sockfd))
		return(1);
	close(filefd);
	close(sockfd);
	return (0);
}
