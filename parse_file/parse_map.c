#include "cub.h"

char	*ft_strjoin_new(char *s1, char *s2, t_map *field)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len1 + 1);
	ft_strlcpy(new + len1, s2, len2 + 1);
	if (ft_strchr(new, '\n'))
		new[len1 + len2 - 1] = '\0';
	return (new);
}

char	*ft_temp_sj(t_map *field, char *line)
{
	char	*tmp;

	if (line == NULL)
		return (field->map_line);
	tmp = ft_strjoin_new(field->map_line, line, field);
	if (field->map_line)
		free (field->map_line);
	if (!tmp)
	{
		free(line);
		ft_exit();
	}
	return (tmp);
}

void    check_valid_map(t_field *field, char **map)
{
	int	height;
	int width;
	int pos_count;

	height = 0;
	width = 0;
	pos_count = 0;
	while (map[height])
	{
		while (map[height][width])
		{
			if (field->map_line[height] == 'N' \
				field->map_line[height] == 'S' \
				field->map_line[height] == 'W' \
				field->map_line[height] == 'E')
			{
				play++;
				field->pos_x = height;
				field->pos_y = width;
			}
			else if (field->map_line[height] != '1' \
				|| field->map_line[height] != '0')
			{
				printf("Error map\n");
				exit(0);
			}
			width++;
		}
		width = 0;
		height++;
	}
	if (play != 1)
		ft_exit();
	check_map(field, map);
}

void	insert_map_tmp(t_field *field, char	**map, char *new_line, int *index)
{
	int		i;
	int		len;
	char	*map;

	i = 0;
	len = 0;
	len = ft_strlen(new_line);
	map = (char *)ft_calloc(sizeof(char) * len);
	if (index != 0 && len > field->max_map_line)
		field->max_map_line = len;
	while (field->map_line[i])
	{
		map[i] = field->map_line[i];
		i++;
	}
	map[index] = new_line;
	return ;
}

static void	read_map(char *map, t_field *field)
{
	int		index;
	int		fd;
	char	*line;
	char	*new_line;
	char	**map_tmp;

	index = 0;
	field->map_line = 0;
	map_tmp = (char **)ft_calloc(sizeof(char *) * 2);
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	new_line = ft_strdup_new(line);
	if (new_line == NULL)
		exit(0);
	insert_map_tmp(field, map_tmp, new_line, &index);
	free(line);
	new_line = field->map_line;
	while (new_line)
	{
		field->height++;
		new_line = get_next_line(fd);
		if (!new_line)
			free_double_point(map_str);
		insert_map_tmp(field, map_tmp, new_line, &index);
		index++;
		field->map_line = ft_temp_sj(field, new_line);
		free(new_line);
	}
	close(fd);
	check_valid_map(field, map_tmp);
}
