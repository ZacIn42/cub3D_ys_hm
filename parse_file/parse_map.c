#include "cub.h"

char	*ft_strdup_new(char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (src == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * strlen(src));
	if (new == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	if (strchr(new, '\n') && i != 0)
		new[i - 1] = '\0';
	else
		new[i] = '\0';
	return (new);
}

char	*ft_strjoin_new(char *s1, char *s2)
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

char	*ft_temp_sj(t_field *field, char *line)
{
	char	*tmp;

	if (line == NULL)
		return (field->map_line);
	tmp = ft_strjoin_new(field->map_line, line);
	if (field->map_line)
		free (field->map_line);
	if (!tmp)
	{
		free(line);
		exit(0);
	}
	return (tmp);
}

void    check_valid_map(t_field *field)
{
	int	height;
	int width;
	int pos_count;

	height = 0;
	width = 0;
	pos_count = 0;
	while (field->map[height])
	{
		while (field->map[height][width])
		{
			if (field->map[height][width] == 'N' \
				|| field->map[height][width] == 'S' \
				|| field->map[height][width] == 'W' \
				|| field->map[height][width] == 'E')
			{
				pos_count++;
				field->pos_x = height;
				field->pos_y = width;
			}
			else if (field->map[height][width] != '1' \
				|| field->map[height][width] != '0')
			{
				printf("Error map\n");
				exit(0);
			}
			width++;
		}
		width = 0;
		height++;
	}
	if (pos_count != 1)
		exit(0);
	check_map(field);
}

void	insert_map_tmp(t_field *field, char *new_line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	len = strlen(new_line);
	if (field->height != 0 && len > field->max_map_line)
		field->max_map_line = len;
	while (field->map[i])
		i++;
	field->map[field->height] = new_line;
	return ;
}

void	read_map(char *map, t_field *field)
{
	int		fd;
	char	*line;
	char	*new_line;

	field->map_line = 0;
	field->height = 0;
	field->map = (char **)malloc(sizeof(char *) * 2);\
	field->map[1] = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	new_line = ft_strdup_new(line);
	if (new_line == NULL)
		exit(0);
	insert_map_tmp(field, new_line);
	free(line);
	new_line = field->map_line;
	while (new_line)
	{
		field->height++;
		new_line = get_next_line(fd);
		// if (!new_line)
		// 	free_double_point(map_str);
		field->height++;
		insert_map_tmp(field, new_line);
		field->map_line = ft_temp_sj(field, new_line);
		free(new_line);
	}
	close(fd);
	check_valid_map(field);
}
