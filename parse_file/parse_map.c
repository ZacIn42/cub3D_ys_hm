/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:02:48 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 16:58:37 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	insert_map_tmp(t_field *field, char *line, int *index)
{
	field->map[*index] = ft_strdup(line);
	(*index)++;
	return ;
}

static char	*ft_strdup_new(char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (src == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(src));
	if (new == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	if (ft_strchr(new, '\n') && i != 0)
		new[i - 1] = '\0';
	else
		new[i] = '\0';
	return (new);
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
	if (!line)
		exit(0);
	while (count < parse->texture_height)
	{
		line = get_next_line(fd);
		if (!line)
			exit(0);
		free(line);
		count++;
	}
	while ((line = get_next_line(fd)) != NULL && *line == '\0')
		free(line);
	if (line == NULL)
		exit(0);
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
	check_valid_map(field, parse);
}
