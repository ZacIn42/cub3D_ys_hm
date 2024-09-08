/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:02:48 by yususato          #+#    #+#             */
/*   Updated: 2024/09/08 14:11:10 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	insert_map_tmp(t_field *field, char *line, int *index)
{
	field->map[*index] = ft_strdup(line);
	if (field->map[*index] == NULL)
		return (perror_return_one("failed to allocate memory\n"));
	(*index)++;
	return (0);
}

static int	skip_texture(t_parse *parse, char **line, int fd, int *count)
{
	*count = 1;
	free(*line);
	while (*count < parse->texture_height)
	{
		*line = get_next_line(fd, &(parse->gnl_flag));
		if (check_gnl_error(*line, parse->gnl_flag, init_error(1)) == 1)
			return (1);
		free(*line);
		(*count)++;
	}
	*line = get_next_line(fd, &(parse->gnl_flag));
	if (check_gnl_error(*line, parse->gnl_flag, init_error(1)) == 1)
		return (1);
	while (*line && **line == '\0')
	{
		free(*line);
		*line = get_next_line(fd, &(parse->gnl_flag));
		if (check_gnl_error(*line, parse->gnl_flag, init_error(1)) == 1)
			return (1);
	}
	if (check_gnl_error(*line, parse->gnl_flag, init_error(1)) == 1)
		return (1);
	return (0);
}

static int	gnl_insert_map(t_field *field, \
					t_parse *parse, char *line, int fd)
{
	int	index;

	index = 0;
	if (insert_map_tmp(field, line, &index) == 1)
		return (free(line), 1);
	free(line);
	while (index < parse->height)
	{
		line = get_next_line(fd, &(parse->gnl_flag));
		if (check_gnl_error(line, parse->gnl_flag, NULL) == 1)
			return (1);
		if (line == NULL)
			break ;
		if (insert_map_tmp(field, line, &index) == 1)
			return (free(line), 1);
		free(line);
	}
	return (0);
}

int	read_map(char *map, t_field *field, t_parse *parse)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (perror_return_one("failed to close map file"));
	field->map = (char **)ft_calloc(sizeof(char *), parse->height + 1);
	if (field->map == NULL)
		return (perror_return_one("failed to allocate memory\n"));
	line = get_next_line(fd, &(parse->gnl_flag));
	if (check_gnl_error(line, parse->gnl_flag, "failed read fail\n") == 1)
		return (1);
	if (skip_texture(parse, &line, fd, &count) == 1)
		return (free(field->map), 1);
	if (gnl_insert_map(field, parse, line, fd) == 1)
		return (free_str_array(field->map), 1);
	if (close(fd) == -1)
		return (free_str_array(field->map), \
		perror_return_one("failed to close map file"));
	return (0);
}
