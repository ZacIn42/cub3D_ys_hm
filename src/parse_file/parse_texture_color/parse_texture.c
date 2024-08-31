/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:32:52 by yususato          #+#    #+#             */
/*   Updated: 2024/08/31 18:17:50 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_valid_texture(t_field *field, char *line, t_parse *parse)
{
	if (line[0] == 'N')
		return (check_texture_north(field, line, parse), 0);
	else if (line[0] == 'S')
		return (check_texture_sorth(field, line, parse), 0);
	else if (line[0] == 'W')
		return (check_texture_west(field, line, parse), 0);
	else if (line[0] == 'E')
		return (check_texture_east(field, line, parse), 0);
	else if (line[0] == 'F')
		return (check_texture_floor(field, line, parse), 0);
	else if (line[0] == 'C')
		return (check_texture_ceiling(field, line, parse), 0);
	else if (line[0] == '\n')
		return (0);
	return (0);
}

static int	read_texture_content(t_field *field, t_parse *parse \
									, char *new_line, int fd)
{
	int	count;

	count = 0;
	while (new_line)
	{
		parse->texture_height++;
		if (*new_line == '\0')
		{
			free(new_line);
			new_line = get_next_line(fd);
			continue ;
		}
		count++;
		if (check_valid_texture(field, new_line, parse) != 0)
			return (1);
		free(new_line);
		if (count == 6)
			break ;
		new_line = get_next_line(fd);
		if (!new_line)
			return (perror_return_one("missing texture and color\n"));
	}
	return (0);
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

int	parse_texture(t_field *field, char *map, t_parse *parse)
{
	int		count;
	int		fd;
	char	*new_line;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (perror(map), perror_return_one("failed to open map file\n"));
	new_line = get_next_line(fd);
	if (new_line == NULL)
		return (perror_return_one("file is empty\n"));
	parse->texture_height = 0;
	if (read_texture_content(field, parse, new_line, fd) != 0)
		return (1);
	check_texture_flag(parse);
	count_map_height(parse, new_line, fd);
	check_height(parse);
	if (close(fd) != 0)
		return (perror(map), perror_return_one("failed to close map file\n"));
	return (0);
}
