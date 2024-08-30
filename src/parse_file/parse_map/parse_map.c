/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:02:48 by yususato          #+#    #+#             */
/*   Updated: 2024/08/30 09:36:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	insert_map_tmp(t_field *field, char *line, int *index)
{
	field->map[*index] = ft_strdup(line);
	(*index)++;
	return ;
}

static void	skip_texture(t_parse *parse, char **line, int fd, int *count)
{
	if (!*line)
		exit(perror_return_one("Faild to malloc\n"));
	while (*count < parse->texture_height)
	{
		*line = get_next_line(fd);
		if (!*line)
			exit(perror_return_one("Failed to malloc\n"));
		free(line);
		(*count)++;
	}
	while ((*line = get_next_line(fd)) != NULL && **line == '\0')
		free(line);
	if (*line == NULL)
		exit(perror_return_one("Failed to malloc\n"));
	return ;
}

void	read_map(char *map, t_field *field, t_parse *parse)
{
	int		count;
	int		index;
	int		fd;
	char	*line;

	index = 0;
	count = 0;
	fd = open(map, O_RDONLY);
	field->map = (char **)ft_calloc(sizeof(char *), parse->height + 1);
	line = get_next_line(fd);
	skip_texture(parse, &line, fd, &count);
	insert_map_tmp(field, line, &index);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		insert_map_tmp(field, line, &index);
		free(line);
	}
	close(fd);
	return ;
}
