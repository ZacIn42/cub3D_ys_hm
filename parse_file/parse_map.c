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

		while (field->map[height][width] && field->map[height][width] != '\0')
		{
			if (field->map[height][width] == 'N' \
				|| field->map[height][width] == 'S' \
				|| field->map[height][width] == 'W' \
				|| field->map[height][width] == 'E')
			{
				pos_count++;
				field->pos_x = width;
				field->pos_y = height;
			}
			else if (field->map[height][width] != '1' \
				&& field->map[height][width] != '0' \
				&& field->map[height][width] != ' ')
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

void	check_line_next(char *line, int *count)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == '\n')
			(*count)++;
		index++;
	}
	return ;
}

void	read_file_height(int fd, int *count)
{
	int		byte_size;
	char	*buf;

	byte_size = 1;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		exit(0);
	while (byte_size > 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		if (byte_size == -1)
		{
			free(buf);
			buf = NULL;
			return ;
		}
		buf[byte_size] = '\0';
		check_line_next(buf, count);
	}
	free(buf);
	return ;
}

int	count_file_height(int fd)
{
	int		count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		exit(0);
	read_file_height(fd, &count);
	return (count);
}

void	check_height(t_field *field)
{
	if (field->height_count < 3)
		exit(0);
	return ;
}

void	insert_map_tmp(t_field *field, char *new_line, int *index)
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
	field->map_line = 0;
	field->height = 0;
	field->height_count = 1;
	fd = open(map, O_RDONLY);
	field->height_count = count_file_height(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	check_height(field);
	field->map = (char **)ft_calloc(sizeof(char *), field->height_count + 1);
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
