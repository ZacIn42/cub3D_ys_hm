#include "cub.h"

static void	check_height(t_field *field)
{
	if (field->height < 3)
		exit(0);
	return ;
}

static void	insert_map_tmp(t_field *field, char *new_line, int *index)
{
	field->map[*index] = ft_strdup(new_line);
	(*index)++;
	return ;
}

void	read_map(char *map, t_field *field)
{
	int		index;
	int		fd;
	char	*line;
	char	*new_line;

	index = 0;
	field->height = 1;
	fd = open(map, O_RDONLY);
	field->height += count_file_height(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	check_height(field);
	field->map = (char **)ft_calloc(sizeof(char *), field->height + 1);
	line = get_next_line(fd);
	new_line = ft_strdup_new(line);
	if (new_line == NULL)
		exit(0);
	insert_map_tmp(field, new_line, &index);
	free(line);
	while (new_line)
	{
		new_line = get_next_line(fd);
	// printf("str%s\n", field->map[index - 1]);
		if (!new_line)
			break ;
		insert_map_tmp(field, new_line, &index);
		free(new_line);
	}
	close(fd);
	check_valid_map(field);
}
