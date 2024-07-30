#include <sft.h>

int	ft_check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 6)
		return (fprintf(stderr, "Usage: %s <send/recive>\n", argv[0]), 0);
	if (!(strcmp(argv[1], "send") || strcmp(argv[1], "recive")))
		return (fprintf(stderr, "Usage: %s <send/recive>\n", argv[0]), 0);
	if (argc != 4 && strcmp(argv[1], "recive") == 0)
		return (fprintf(stderr, "Usage: %s <send/recive> <port> <filename>\n", argv[0]), 0);
	if (argc != 5 && strcmp(argv[1], "send") == 0)
		return (fprintf(stderr, "Usage: %s <send/recive> <ip> <port> <file>\n", argv[0]), 0);
	return (1);
}
