#include "cub.h"

void	check_filename(int ac, char *av)
{
	char	*file;

	if (ac != 2)
		exit(0);
	file = strrchr(av, '.');
	if (file == NULL)
		exit(0);
	if (strncmp(file, ".cub\0", 5) != 0)
		exit(0);
}