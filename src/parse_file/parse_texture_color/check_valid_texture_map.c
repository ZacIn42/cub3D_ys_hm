#include "cub.h"

static int	check_height(t_parse *parse)
{
	if (parse->height < 3)
		return (perror_return_one("map is invalid\n"));
	return (0);
}

static int	check_texture_flag(t_parse *parse)
{
	if (parse->north_flag == true && parse->sorth_flag == true \
		&& parse->west_flag == true && parse->east_flag == true \
		&& parse->ceiling_flag == true && parse->floor_flag == true)
		return (0);
	return (perror_return_one("argument is invalid\n"));
}

static int	count_map_height(t_parse *parse, char *new_line, int fd)
{
	new_line = get_next_line(fd);
	while (new_line && *new_line == '\0')
	{
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line == NULL)
		return (perror_return_one("map is empty\n"));
	parse->height = 1;
	free(new_line);
	new_line = get_next_line(fd);
	while (new_line)
	{
		parse->height++;
		if (*new_line == '\0')
			return (perror_return_one("blank in the middle of the map\n"));
		free(new_line);
		new_line = get_next_line(fd);
	}
	return (0);
}

int	check_valid_texture_map(char **new_line, t_parse *parse, int fd)
{
	if (check_texture_flag(parse) == 1)
		return (1);
	if (count_map_height(parse, *new_line, fd) ==1)
		return (1);
	if (check_height(parse) == 1)
		return (1);
	return (0);
}