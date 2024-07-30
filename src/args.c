#include <sft.h>

int	ft_check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 6)
		return (fprintf(stderr, "Usage: %s <send/recv>\n", argv[0]), 0);
	if (!(strcmp(argv[1], "send") || strcmp(argv[1], "recv")))
		return (fprintf(stderr, "Usage: %s <send/recv>\n", argv[0]), 0);
	if (argc != 4 && strcmp(argv[1], "recv") == 0)
		return (fprintf(stderr, "Usage: %s <send/recv> <port> <filename>\n", argv[0]), 0);
	if (argc != 5 && strcmp(argv[1], "send") == 0)
		return (fprintf(stderr, "Usage: %s <send/recv> <ip> <port> <file>\n", argv[0]), 0);
	return (1);
}
