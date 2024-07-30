#ifndef SFT_H
# define SFT_H

# include <sys/socket.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int	ft_check_args(int argc, char **argv);
int	ft_recive(int port, char *filename);
int ft_send(char *ip, int port, char *filename);

#endif
