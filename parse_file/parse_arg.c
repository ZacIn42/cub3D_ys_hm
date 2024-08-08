#include "cub.h"

static void	check_filename(int ac, char *av)
{
	char	*a;

	if (ac != 2)
		ft_exit();
	a = ft_strrchr(av, '.');
	if (a == NULL)
		ft_exit();
	if (ft_strncmp(a, ".ber\0", 5) != 0)
		ft_exit();
}