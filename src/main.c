#include <sft.h>

int	main(int argc, char **argv)
{
	if (!ft_check_args(argc, argv))
		return (1);
	if (strcmp(argv[1], "recive") == 0)
			return (ft_recive(atoi(argv[2]), argv[3]));
	else
			return (ft_send(argv[2], atoi(argv[3]), argv[4]));
	return (0);
}
